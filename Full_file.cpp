#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
#include<ctime>
#include<climits>
#include<cstring>
using namespace std;
class welcome{
    public:
    void showTitle() {
        cout << "\n";
        cout << "  _     _  _   _  ____    ___  \n";
        cout << " | |   | || | | ||  _    / _   \n";
        cout << " | |   | || | | || | | || | | |\n";
        cout << " | |___| || |_| || |_| || |_| |\n";
        cout << " |_____|_|   __/ |____/    __/ \n";
        cout << "\n";
        cout << "Welcome to the Classic Game of Ludo!\n";
        cout << "====================================\n\n";
    }
    void pb(vector<string>&board ,int n) {
        if(n==2) {
            board = {
    "  A   A     . . .            ",
    "            . . *            ",
    "  A   A     * . .            ",
    "            . . .            ",
    "            . . .            ",
    ". * . . . . . H . . . . * . .",
    ". 1 1 1 1 1 H H H 2 2 2 2 2 .",
    ". . * . . . . H . . . . . * .",
    "            . . .            ",
    "            . . .            ",
    "            . . *     B   B  ",
    "            * . .            ",
    "            . . .     B   B  ",
};
        }
        else if(n==3) {
              board= {
    "  A   A     . 2 .     B   B ",
    "            . 2 *           ",
    "  A   A     * 2 .     B   B ",
    "            . 2 .           ",
    "            . 2 .           ",
    ". * . . . . . H . . . . * . .",
    ". 1 1 1 1 1 H H H 3 3 3 3 3 .",
    ". . * . . . . H . . . . . * .",
    "            . . .           ",
    "            . . .           ",
    "            . . *     C   C ",
    "            * . .           ",
    "            . . .     C   C ",
};
        }
        else {
            board= {
    "  A   A     . . .     B   B ",
    "            . 2 *           ",
    "  A   A     * 2 .     B   B ",
    "            . 2 .           ",
    "            . 2 .           ",
    ". * . . . . . H . . . . * . .",
    ". 1 1 1 1 1 H H H 3 3 3 3 3 .",
    ". . * . . . . H . . . . . * .",
    "            . 4 .           ",
    "            . 4 .           ",
    "  D   D     . 4 *     C   C ",
    "            * 4 .           ",
    "  D   D     . . .     C   C ",
};
        }
        cout<<"\n\nInitial board :-\n\n";
        for(string s:board) {
            cout<<s<<endl;
        }
    }
    void th() {
        cout<<"Kindly Enter the number of players :(2-4)";
    }
    bool th2(int n) {
        
        if(n==2) {
            cout<<"The number of players selected are "<<n<<endl;
        cout<<"Houses information :- \n";
             cout<<"Player 1 --> House A \n";
        cout<<"Player 2 --> House B \n";
        }
        else if(n==3) {
            cout<<"The number of players selected are "<<n<<endl;
        cout<<"Houses information :- \n";
            cout<<"Player 1 --> House A \n";
        cout<<"Player 2 --> House B \n";
        cout<<"Player 3 --> House C \n";
        }
        else if(n==4) {
            cout<<"The number of players selected are "<<n<<endl;
        cout<<"Houses information :- \n";
        cout<<"Player 1 --> House A \n";
        cout<<"Player 2 --> House B \n";
        cout<<"Player 3 --> House C \n";
        cout<<"Player 4 --> House D \n";
        }
        else {
            cout<<"You have selected "<<n<<" which is an ";
            cout<<"Invalid selection ;\n";
            cout<<"Kindly start the game again and make a valid selection for number of players b/w 1 & 4\n";
            return false;
        }
        cout<<"Press Enter key to continue :";
        cin.get();
        cout<<"\n";
        return true;
    }
};
vector<int>F(int currentplayer,int t6,vector<int>&numbers) {
    cout << "Press Enter to roll the dice --> ";
    cin.get();
    int diceRoll=(rand()%6)+1;
    numbers.push_back(diceRoll);
    cout << "\nPlayer " << currentplayer << " rolled a " << diceRoll << "!\n";
    if(diceRoll==6 and t6<2) {
        t6++;
        cout<<"You got a 6 so you can roll again\n";
        F(currentplayer,t6,numbers);
    }
    else if(diceRoll==6) {
        cout<<"you got 3 6's in a row hence your turn is terminated!\n";
        numbers.clear();
    }
        return numbers;
}
vector<int> turn(int currentplayer) {
    int t6=0;
vector<int>numbers;
    return F(currentplayer,t6,numbers);
}

class Pawn {
public:
    int position;      // -1 = in base, 0-56 = track/home stretch
    bool isHome;       // true if reached center H (position 56)
    bool isActive;     // true if on track

    Pawn() {
        position = -1;
        isHome = false;
        isActive = false;
    }
};
class Player {
public:
    char house;           // 'A', 'B', 'C', 'D'
    int startOffset;      // Where they enter outer track
    Pawn pawns[4];        // 4 pawns each

    Player() {}
// parameterised constructor
// initially house a initial is 0
// house b initial 13
// house c iitial26
// house d initial 39
// (for generalisation)
    Player(char h, int offset) {
        house = h;
        startOffset = offset;
    }
//returns the number of pawns that are at home
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
int main() {
    srand(time(0));

    bool winner = false;
    int currentPlayerIdx = 0;
    int numPlayers;

    vector<string> board;
    welcome w;
    w.showTitle();
    w.th();

    cin >> numPlayers;
    cin.get();

    if (w.th2(numPlayers) == false) {
        cout << "\nGame ends\n";
        return 0;
    }

    w.pb(board, numPlayers);

    cout << "\nRules:\n";
    cout << "1. Roll 6 to unlock pawn from base\n";
    cout << "2. Move pawns by dice value\n";
    cout << "3. Capture opponents by landing on them (not safe spots)\n";
    cout << "4. Reach home with exact roll\n";
    cout << "5. First to get all 4 pawns home wins!\n\n";

    Player players[4] = {
        Player('A', 0),
        Player('B', 13),
        Player('C', 26),
        Player('D', 39)
    };

    GameLogic logic;
    logic.showStatus(players, numPlayers);

    cout << "\n========== GAME START ==========\n";

    while (!winner) {
        Player &p = players[currentPlayerIdx];
        bool earnedExtra = true;  // Start true to enter the loop at least once

        // ============ EXTRA TURN LOOP ============
        // Keep giving turns while player earns extras
        while (earnedExtra && !winner) {
            earnedExtra = false;  // Reset for this turn

            cout << "\n--------------------------------\n";
            cout << "PLAYER " << p.house << "'s TURN\n";
            cout << "--------------------------------\n";

            logic.showStatus(players, numPlayers);

            // Collect dice rolls
            vector<int> rolls = turn(currentPlayerIdx + 1);

            if (rolls.empty()) {
                cout << "\nTurn ended (3 sixes).\n";
                break;  // Exit extra turn loop
            }

            cout << "\nRolls: ";
            for (int r : rolls) cout << r << " ";
            cout << "\n";

            // Process each roll
            for (int dice : rolls) {
                vector<int> valid = logic.getValidPawns(p, dice);

                if (valid.empty()) {
                    cout << "\nNo valid moves for " << dice << ".\n";
                    continue;
                }

                cout << "\nValid pawns: ";
                for (int id : valid) cout << (id + 1) << " ";
                cout << "\nSelect pawn: ";

                int choice;
                cin >> choice;
                cin.ignore();
                choice--;

                bool ok = false;
                for (int id : valid) {
                    if (id == choice) ok = true;
                }
                if (!ok) {
                    cout << "Invalid! Skipping.\n";
                    continue;
                }

                // Move and check if extra turn earned
                bool extra = logic.movePawn(players, numPlayers, currentPlayerIdx, choice, dice);
                logic.showStatus(players, numPlayers);
                logic.askAndShowBoard(board);

                if (extra) {
                    earnedExtra = true;
                    cout << "\n*** Extra turn earned! ***\n";
                }
            }

            // Check win after all rolls processed
            if (p.pawnsAtHome() == 4) {
                winner = true;
                cout << "\n\n>>> PLAYER " << p.house << " WINS! <<<\n";
                break;
            }
        }

        // Move to next player only if game not over
        if (!winner) {
            currentPlayerIdx = (currentPlayerIdx + 1) % numPlayers;
        }
    }

    cout << "\n========== GAME OVER ==========\n";
    return 0;
}
