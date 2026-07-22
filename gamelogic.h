#include"player.h"
class GameLogic {
public:
    int safeSpots[8] = {0, 8, 13, 21, 26, 34, 39, 47};

    int trackRow[52] = {
        0, 0, 0, 1, 2, 2,
        3, 4, 5, 5, 5, 5,
        5, 5, 6, 6, 6, 6,
        7, 7, 7, 7, 8, 9,
        10, 10, 11, 12, 12, 12,
        11, 10, 9, 8, 7, 7,
        7, 7, 6, 6, 6, 6,
        5, 5, 5, 5, 4, 3,
        2, 2, 1, 0
    };

    int trackCol[52] = {
        13, 15, 17, 17, 15, 13,
        13, 13, 13, 15, 17, 19,
        21, 23, 23, 21, 19, 17,
        17, 15, 13, 11, 11, 11,
        11, 13, 13, 13, 15, 17,
        17, 17, 17, 17, 17, 15,
        13, 11, 11, 13, 15, 17,
        17, 15, 13, 11, 11, 11,
        13, 15, 15, 13
    };

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

    // ============ BOARD DISPLAY WITH TOGGLE ============

    void showBoard(Player players[], int numPlayers, vector<string> &baseBoard) {
        vector<string> board = baseBoard;

        for (int p = 0; p < numPlayers; p++) {
            Player &player = players[p];
            char symbol = player.house;

            for (int i = 0; i < 4; i++) {
                Pawn &pawn = player.pawns[i];
                int row = -1, col = -1;

                if (pawn.position == -1) {
                    if (player.house == 'A') {
                        int basePos[4][2] = {{0,2}, {0,6}, {2,2}, {2,6}};
                        row = basePos[i][0]; col = basePos[i][1];
                    }
                    else if (player.house == 'B') {
                        int basePos[4][2] = {{0,22}, {0,26}, {10,22}, {10,26}};
                        row = basePos[i][0]; col = basePos[i][1];
                    }
                    else if (player.house == 'C') {
                        int basePos[4][2] = {{10,22}, {10,26}, {12,22}, {12,26}};
                        row = basePos[i][0]; col = basePos[i][1];
                    }
                    else if (player.house == 'D') {
                        int basePos[4][2] = {{10,2}, {10,6}, {12,2}, {12,6}};
                        row = basePos[i][0]; col = basePos[i][1];
                    }
                }
                else if (pawn.position >= 0 && pawn.position <= 50) {
                    int absPos = getAbsPos(player, pawn.position);
                    row = trackRow[absPos];
                    col = trackCol[absPos];
                }
                else if (pawn.position >= 51 && pawn.position < 56) {
                    int homeRow[4][5] = {
                        {6, 6, 6, 6, 6},
                        {6, 6, 6, 6, 6},
                        {6, 6, 6, 6, 6},
                        {6, 6, 6, 6, 6}
                    };
                    int homeCol[4][5] = {
                        {1, 2, 3, 4, 5},
                        {19, 20, 21, 22, 23},
                        {19, 20, 21, 22, 23},
                        {1, 2, 3, 4, 5}
                    };
                    int playerIdx = player.house - 'A';
                    int stretchIdx = pawn.position - 51;
                    row = homeRow[playerIdx][stretchIdx];
                    col = homeCol[playerIdx][stretchIdx];
                }
                else if (pawn.isHome) {
                    int centerPos[4][2] = {{5,13}, {5,15}, {6,13}, {6,15}};
                    int playerIdx = player.house - 'A';
                    row = centerPos[playerIdx][0];
                    col = centerPos[playerIdx][1];
                }

                if (row >= 0 && row < board.size() && col >= 0 && col < board[row].length()) {
                    board[row][col] = symbol;
                }
            }
        }

        cout << "\n========== CURRENT BOARD ==========\n\n";
        for (string &line : board) {
            cout << line << "\n";
        }
        cout << "\n===================================\n";
    }

    // NEW: Ask if player wants to see board, then show it
    void askAndShowBoard(Player players[], int numPlayers, vector<string> &baseBoard) {
        int choice;
        cout << "\nShow board? (1 = Yes, 0 = No): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showBoard(players, numPlayers, baseBoard);
        }
    }
};
