#include"pawn.h"
class Player {
public:
    char house;           // 'A', 'B', 'C', 'D'
    int startOffset;      // Where they enter outer track
    Pawn pawns[4];        // 4 pawns each

    Player() {}

    Player(char h, int offset) {
        house = h;
        startOffset = offset;
    }

    int pawnsAtHome() {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (pawns[i].isHome) count++;
        }
        return count;
    }

    void showPawns() {
        cout << "\nPlayer " << house << " pawns:\n";
        for (int i = 0; i < 4; i++) {
            cout << "  Pawn " << (i + 1) << ": ";
            if (pawns[i].position == -1) {
                cout << "In base\n";
            }
            else if (pawns[i].isHome) {
                cout << "HOME!\n";
            }
            else if (pawns[i].position >= 51) {
                cout << "Home stretch at " << pawns[i].position << "\n";
            }
            else {
                cout << "On track at " << pawns[i].position << "\n";
            }
        }
    }
};
