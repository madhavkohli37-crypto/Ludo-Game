#include "player.h"

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

    // ============ BOARD DISPLAY ============

    void askAndShowBoard(vector<string> &v) {
        bool choice;
        cout << "\nShow board? (1 = Yes, 0 = No): ";
        cin >> choice;
        cin.ignore();

        if (choice == true) {
            for (string s : v) {
                cout << s << endl;
            }
        }
    }

    // ============ STATUS DISPLAY ============

    void showStatus(Player players[], int numPlayers) {
        cout << "\n========== PAWN STATUS ==========\n";
        for (int p = 0; p < numPlayers; p++) {
            cout << "Player " << players[p].house << ": ";
            for (int i = 0; i < 4; i++) {
                Pawn &pawn = players[p].pawns[i];
                cout << "P" << (i + 1) << "[";
                if (pawn.position == -1) cout << "base";
                else if (pawn.isHome) cout << "HOME";
                else if (pawn.position >= 51) cout << "stretch:" << pawn.position;
                else cout << "track:" << pawn.position;
                cout << "]  ";
            }
            cout << "\n";
        }
        cout << "=================================\n";
    }

    // ============ CAPTURE LOGIC ============

    pair<int, int> checkCapture(Player players[], int numPlayers, int movingPlayerIdx, int absPos) {
        if (isSafe(absPos)) return {-1, -1};

        for (int p = 0; p < numPlayers; p++) {
            if (p == movingPlayerIdx) continue;

            for (int pawnId = 0; pawnId < 4; pawnId++) {
                Pawn &enemy = players[p].pawns[pawnId];

                if (enemy.position >= 0 && enemy.position <= 50 && !enemy.isHome) {
                    int enemyAbsPos = getAbsPos(players[p], enemy.position);

                    if (enemyAbsPos == absPos) {
                        return {p, pawnId};
                    }
                }
            }
        }
        return {-1, -1};
    }

    void sendToBase(Player &player, int pawnId) {
        player.pawns[pawnId].position = -1;
        player.pawns[pawnId].isActive = false;
        player.pawns[pawnId].isHome = false;
        cout << "Player " << player.house << "'s Pawn " << (pawnId + 1)
             << " was CAPTURED and sent back to base!\n";
    }

    // ============ MOVE PAWN ============

    bool movePawn(Player players[], int numPlayers, int movingPlayerIdx, int pawnId, int dice) {
        Player &player = players[movingPlayerIdx];
        Pawn &p = player.pawns[pawnId];

        // Unlock from base
        if (p.position == -1) {
            if (dice != 6) {
                cout << "Pawn " << (pawnId + 1) << " is in base. Need a 6 to unlock!\n";
                return false;
            }
            p.position = 0;
            p.isActive = true;
            cout << "Pawn " << (pawnId + 1) << " unlocked! Entered the track.\n";
            return true;
        }

        int newPos = p.position + dice;

        if (newPos > 56) {
            cout << "Need exact roll to reach home. Can't move.\n";
            return false;
        }

        p.position = newPos;

        // Reached home
        if (newPos == 56) {
            p.isHome = true;
            cout << "Pawn " << (pawnId + 1) << " reached HOME!\n";
            return true;
        }

        // Home stretch
        if (newPos >= 51) {
            cout << "Pawn " << (pawnId + 1) << " entered home stretch at position " << newPos << "\n";
            return false;
        }

        // On track - check for capture
        int absPos = getAbsPos(player, newPos);
        cout << "Pawn " << (pawnId + 1) << " moved to track position " << newPos;
        cout << " (absolute: " << absPos << ")\n";

        if (isSafe(absPos)) {
            cout << "Landed on a safe spot - cannot be captured here!\n";
            return false;
        }

        pair<int, int> captured = checkCapture(players, numPlayers, movingPlayerIdx, absPos);

        if (captured.first != -1) {
            sendToBase(players[captured.first], captured.second);
            cout << ">> CAPTURE SUCCESSFUL! You get an extra turn! <<\n";
            return true;
        }

        return false;
    }

    // ============ EXTRA TURN HANDLING ============
    // This function handles a complete turn (roll + move) for one player
    // Returns true if the player earned an extra turn (can be called again)

    bool playTurn(Player players[], int numPlayers, int currentPlayerIdx, vector<string> &board) {
        Player &p = players[currentPlayerIdx];

        cout << "\n--------------------------------\n";
        cout << "PLAYER " << p.house << "'s TURN\n";
        cout << "--------------------------------\n";

        // Show current status
        showStatus(players, numPlayers);

        // Collect dice rolls (from turn.h)
        // NOTE: You'll need to include turn.h and call turn() from main,
        // or pass the rolls vector as parameter. 
        // For now, this is a placeholder structure.

        // Since turn() is in turn.h and uses cin.get(), we can't easily call it here
        // without including. So the extra turn loop should be in main.cpp instead.
        
        // This function is kept simple - the extra turn loop goes in main
        return false;
    }
};
