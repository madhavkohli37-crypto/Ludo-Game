#include"player.h"
class GameLogic {
public:
    int safeSpots[8] = {0, 8, 13, 21, 26, 34, 39, 47};
    bool isSafe(int absPos) {
        for (int i = 0; i < 8; i++) {
            if (safeSpots[i] == absPos) return true;
        }
        return false;
    }

    int getAbsPos(Player &player, int relPos) {
        if (relPos < 0 || relPos > 50) return -1;
        return (player.startOffset + relPos) % 52;
    }

    vector<int> getValidPawns(Player &player, int dice) {
        vector<int> valid;
        for (int i = 0; i < 4; i++) {
            if (player.pawns[i].position == -1) {
                if (dice == 6) valid.push_back(i);
            }
            else if (!player.pawns[i].isHome) {
                if (player.pawns[i].position + dice <= 56) {
                    valid.push_back(i);
                }
            }
        }
        return valid;
    }

    bool movePawn(Player &player, int pawnId, int dice) {
        Pawn &p = player.pawns[pawnId];

        if (p.position == -1) {
            if (dice != 6) {
                cout << "Pawn " << (pawnId + 1) << " in base. Need 6!\n";
                return false;
            }
            p.position = 0;
            p.isActive = true;
            cout << "Pawn " << (pawnId + 1) << " unlocked! On track.\n";
            return true;
        }

        int newPos = p.position + dice;

        if (newPos > 56) {
            cout << "Need exact roll for home. Can't move.\n";
            return false;
        }

        p.position = newPos;

        if (newPos == 56) {
            p.isHome = true;
            cout << "Pawn " << (pawnId + 1) << " reached HOME!\n";
            return true;
        }

        if (newPos >= 51) {
            cout << "Pawn " << (pawnId + 1) << " on home stretch at " << newPos << "\n";
            return false;
        }

        int absPos = getAbsPos(player, newPos);
        cout << "Pawn " << (pawnId + 1) << " moved to " << newPos;
        cout << " (abs: " << absPos << ")\n";

        if (isSafe(absPos)) {
            cout << "Safe spot!\n";
        }

        return false;
    }
    // NEW: Ask if player wants to see board, then show it
    void askAndShowBoard( vector<string> &v) {
        bool choice;
        cout << "\nShow board? (1 = Yes, 0 = No): ";
        cin >> choice;
        cin.ignore();

        if (choice == true) {
           for(string s : v) {
            cout << s<< endl;
           }
         }
    }
    // ============ CAPTURE (TRAP) LOGIC ============

    // Check if any opponent is at this absolute position
    // Returns {enemyPlayerIdx, enemyPawnIdx} or {-1, -1} if none
    pair<int, int> checkCapture(Player players[], int numPlayers, int movingPlayerIdx, int absPos) {
        // Can't capture on safe spots
        if (isSafe(absPos)) return {-1, -1};

        for (int p = 0; p < numPlayers; p++) {
            if (p == movingPlayerIdx) continue; // Skip yourself

            for (int pawnId = 0; pawnId < 4; pawnId++) {
                Pawn &enemy = players[p].pawns[pawnId];

                // Only check pawns that are active on the outer track
                // (not in base, not on home stretch, not already home)
                if (enemy.position >= 0 && enemy.position <= 50 && !enemy.isHome) {
                    int enemyAbsPos = getAbsPos(players[p], enemy.position);

                    if (enemyAbsPos == absPos) {
                        // FOUND! Return who to capture
                        return {p, pawnId};
                    }
                }
            }
        }
        return {-1, -1}; // No one to capture
    }

    // Send a captured pawn back to base
    void sendToBase(Player &player, int pawnId) {
        player.pawns[pawnId].position = -1;
        player.pawns[pawnId].isActive = false;
        player.pawns[pawnId].isHome = false;
        cout << "Player " << player.house << "'s Pawn " << (pawnId + 1)
             << " was CAPTURED and sent back to base!\n";
    }

    // ============ MOVE PAWN (with capture support) ============

    // Now takes all players array to check for captures
    bool movePawn(Player players[], int numPlayers, int movingPlayerIdx, int pawnId, int dice) {
        Player &player = players[movingPlayerIdx];
        Pawn &p = player.pawns[pawnId];

        // CASE 1: Pawn in base - need 6 to unlock
        if (p.position == -1) {
            if (dice != 6) {
                cout << "Pawn " << (pawnId + 1) << " is in base. Need a 6 to unlock!\n";
                return false;
            }
            p.position = 0;
            p.isActive = true;
            cout << "Pawn " << (pawnId + 1) << " unlocked! Entered the track.\n";
            return true;  // Extra turn for rolling 6
        }

        // Calculate new position
        int newPos = p.position + dice;

        // Can't overshoot home (need exact roll)
        if (newPos > 56) {
            cout << "Need exact roll to reach home. Can't move.\n";
            return false;
        }

        // Move the pawn
        p.position = newPos;

        // CASE 2: Reached center home (position 56)
        if (newPos == 56) {
            p.isHome = true;
            cout << "Pawn " << (pawnId + 1) << " reached HOME!\n";
            return true;  // Extra turn for reaching home
        }

        // CASE 3: On home stretch (positions 51-55)
        if (newPos >= 51) {
            cout << "Pawn " << (pawnId + 1) << " entered home stretch at position " << newPos << "\n";
            return false;
        }

        // CASE 4: On outer track - check for captures!
        int absPos = getAbsPos(player, newPos);
        cout << "Pawn " << (pawnId + 1) << " moved to track position " << newPos;
        cout << " (absolute: " << absPos << ")\n";

        // Check if landed on safe spot
        if (isSafe(absPos)) {
            cout << "Landed on a safe spot - cannot be captured here!\n";
            return false;
        }

        // Try to capture opponent!
        pair<int, int> captured = checkCapture(players, numPlayers, movingPlayerIdx, absPos);

        if (captured.first != -1) {
            int enemyPlayerIdx = captured.first;
            int enemyPawnIdx = captured.second;
            sendToBase(players[enemyPlayerIdx], enemyPawnIdx);
            cout << ">> CAPTURE SUCCESSFUL! You get an extra turn! <<\n";
            return true;  // Extra turn for capture
        }

        return false; // No extra turn
    }
};
