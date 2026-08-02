#include "player.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <climits>
#include <thread>
#include <chrono>

using namespace std;
void Delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
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

    void askAndShowBoard(vector<string> &board, Player players[], int numPlayers) {
        int choice;
        
        // Bulletproof input
        while (true) {
            cout << "\n🗺️  Show board? 👀 (1 = Yes, 0 = No): ";
            cin >> choice;
            Delay(1000);

            if (cin.fail() || (choice != 0 && choice != 1)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "⚠️  [!] Invalid input! Please enter 1 or 0... even a bot wouldn't mess that up. 🤡 🤖 ❌\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break; 
            }
        }

        if (choice == 1) {
            vector<string> tempBoard = board;
            for (int r = 0; r < tempBoard.size(); r++) {
                for (int c = 0; c < tempBoard[r].size(); c++) {
                    if (tempBoard[r][c] == 'A' || tempBoard[r][c] == 'B' || 
                        tempBoard[r][c] == 'C' || tempBoard[r][c] == 'D') {
                        tempBoard[r][c] = ' ';
                    }
                }
            }

            int trackX[52] = {5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 6, 7, 7, 7, 7, 7, 7, 7, 8, 9, 10, 11, 12, 12, 12, 11, 10, 9, 8, 7, 7, 7, 7, 7, 7, 7, 6, 5};
            int trackY[52] = {2, 4, 6, 8, 10, 12, 12, 12, 12, 12, 12, 14, 16, 16, 16, 16, 16, 16, 18, 20, 22, 24, 26, 28, 28, 28, 26, 24, 22, 20, 18, 16, 16, 16, 16, 16, 16, 14, 12, 12, 12, 12, 12, 12, 10, 8, 6, 4, 2, 0, 0, 0};
            
            for (int i = 0; i < numPlayers; i++) {
                char h = players[i].house;  
                for (int pId = 0; pId < 4; pId++) {
                    Pawn &p = players[i].pawns[pId];
                    int r = -1, c = -1;
                    if (p.position == -1) {
                        if (h == 'A') { int bx[] = {0, 0, 2, 2}; int by[] = {2, 6, 2, 6}; r = bx[pId]; c = by[pId]; }
                        else if (h == 'B') { int bx[] = {0, 0, 2, 2}; int by[] = {22, 26, 22, 26}; r = bx[pId]; c = by[pId]; }
                        else if (h == 'C') { int bx[] = {10, 10, 12, 12}; int by[] = {22, 26, 22, 26}; r = bx[pId]; c = by[pId]; }
                        else if (h == 'D') { int bx[] = {10, 10, 12, 12}; int by[] = {2, 6, 2, 6}; r = bx[pId]; c = by[pId]; }
                    } 
                    else if (p.position >= 0 && p.position <= 50 && !p.isHome) {
                        int absPos = getAbsPos(players[i], p.position);
                        if(absPos >= 0 && absPos < 52) {
                            r = trackX[absPos];
                            c = trackY[absPos];
                        }
                    } 
                    else if (p.position >= 51 && p.position <= 55) {
                        int idx = p.position - 51;
                        if (h == 'A') { int hx[] = {6, 6, 6, 6, 6}; int hy[] = {2, 4, 6, 8, 10}; r = hx[idx]; c = hy[idx]; }
                        else if (h == 'B') { int hx[] = {1, 2, 3, 4, 5}; int hy[] = {14, 14, 14, 14, 14}; r = hx[idx]; c = hy[idx]; }
                        else if (h == 'C') { int hx[] = {6, 6, 6, 6, 6}; int hy[] = {26, 24, 22, 20, 18}; r = hx[idx]; c = hy[idx]; }
                        else if (h == 'D') { int hx[] = {11, 10, 9, 8, 7}; int hy[] = {14, 14, 14, 14, 14}; r = hx[idx]; c = hy[idx]; }
                    } 
                    else if (p.isHome || p.position == 56) {
                        if (h == 'A') { r = 6; c = 12; }
                        else if (h == 'B') { r = 5; c = 14; }
                        else if (h == 'C') { r = 6; c = 16; }
                        else if (h == 'D') { r = 7; c = 14; }
                    }
                    if (r != -1 && c != -1 && r < tempBoard.size() && c < tempBoard[r].size()) {
                        tempBoard[r][c] = h;
                    }
                }
            }
            for (string s : tempBoard) {
                cout << s << endl;
            }
        }
    }

    void showStatus(Player players[], int numPlayers) {
        Delay(1000);
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
        Delay(500);
       cout << "💥 OOF! " << player.house << "'s Pawn " << (pawnId + 1) << " was brutally CAPTURED and sent crying back to base! 💀 🏃 💨\n";
       Delay(1500);
    }

    bool movePawn(Player players[], int numPlayers, int movingPlayerIdx, int pawnId, int dice) {
        Delay(500);
        Player &player = players[movingPlayerIdx];
        Pawn &p = player.pawns[pawnId];

        // Unlock from base
        if (p.position == -1) {
            if (dice != 6) {
                cout << "🔒  Pawn " << (pawnId + 1) << " is trapped in base jail! You need a miraculous 6 to bust them out! 🎲 ⏳\n";
                Delay(1500);
                return false;
            }
            p.position = 0;
            p.isActive = true;
            cout << "🔓 ✨ Pawn " << (pawnId + 1) << " is finally unlocked and charging onto the track! Let's go! 🚀 🔥\n";
            Delay(1500);
            return false;
        }

        int newPos = p.position + dice;

        if (newPos > 56) {
            cout << "🛑 So close yet so far! You need the exact roll to enter home. Hang on right at the doorstep! 🚪 ❌\n";
            Delay(1500);
            return false;
        }

        p.position = newPos;
        if (newPos == 56) {
            p.isHome = true;
            cout << "🎉 🏆  ABSOLUTE LEGEND! Pawn " << (pawnId + 1) << " safely reached HOME! Touchdown! 🥳 🏠 ✨\n";
            Delay(1500);
            return true;
        }
        if (newPos >= 51) {
            cout << "🏃 💨 Boom! Pawn " << (pawnId + 1) << " entered the home stretch at position " << newPos << "! The finish line is right there! 🏁 ✨\n";
            Delay(1500);
            return false;
        }
        int absPos = getAbsPos(player, newPos);
        cout << "👟 💨  Pawn " << (pawnId + 1) << " advances to track position " << newPos;
cout << " (absolute: " << absPos << ") 🎯✨\n";
Delay(1500);

        if (isSafe(absPos)) {
            cout << "🛡️  Sanctuary reached! Landed on a safe spot—you're completely shielded from enemy captures here! 🏰 ✨\n";
            Delay(1500);
            return false;
        }
        pair<int, int> captured = checkCapture(players, numPlayers, movingPlayerIdx, absPos);

        if (captured.first != -1) {
            sendToBase(players[captured.first], captured.second);
            cout << "⚔️ 💥  >> CAPTURE SUCCESSFUL! Enemy sent packing! Enjoy your bonus extra turn! 🚀 🔥 <<\n";
            Delay(1500);
            return true;
        }

        return false;
    }
};
