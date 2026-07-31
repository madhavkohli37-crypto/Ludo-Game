#include <iostream>
#include <vector>
#include <map>
#include <limits> // Required for bulletproofing

using namespace std;

class welcome {
public:
    void text() {
        cout << "\n";
        cout << "+-------------------------------------------------------------+\n";
        cout << "|                  PRO TIPS & STRATEGY                        |\n";
        cout << "+-------------------------------------------------------------+\n";
        cout << "|                                                             |\n";
        cout << "|  [1] UNLOCK EARLY                                           |\n";
        cout << "|      Unlock multiple pawns to increase movement options.    |\n";
        cout << "|                                                             |\n";
        cout << "|  [2] USE SAFE CELLS (*)                                     |\n";
        cout << "|      Protect your pawns from capture on Safe Cells.         |\n";
        cout << "|                                                             |\n";
        cout << "|  [3] CAPTURE OPPONENTS                                      |\n";
        cout << "|      Send them back to base and earn an extra turn!         |\n";
        cout << "|                                                             |\n";
        cout << "|  [4] AVOID EXPOSURE                                         |\n";
        cout << "|      Don't leave pawns vulnerable near enemies.             |\n";
        cout << "|                                                             |\n";
        cout << "|  [5] PLAN AHEAD                                             |\n";
        cout << "|      Spread pawns instead of moving the same one always.    |\n";
        cout << "|                                                             |\n";
        cout << "|  [6] EXTRA TURNS                                            |\n";
        cout << "|      Rolling 6, reaching HOME, or capturing = extra roll!   |\n";
        cout << "|                                                             |\n";
        cout << "|  [7] EXACT ROLL FOR HOME                                    |\n";
        cout << "|      Overshooting means you cannot move that turn.          |\n";
        cout << "|                                                             |\n";
        cout << "+-------------------------------------------------------------+\n";
        cout << "|              Good Luck & Have Fun!                          |\n";
        cout << "+-------------------------------------------------------------+\n";
        cout << "\n        >>>  LET THE GAME BEGIN!  <<<\n\n";
        cout << "(PRESS ENTER TO CONTINUE)\n\n";
        cin.get();
    }

    bool fun(int n) {
        if (n == 2) {
            cout << "\n";
            cout << "╔══════════════════════════════════════════════════════════════╗\n";
            cout << "║                    LUDO RULEBOOK                             ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  1. SETUP                                                    ║\n";
            cout << "║     • 2-4 players can play                                   ║\n";
            cout << "║     • Each player gets 4 pawns in their base                 ║\n";
            cout << "║     • Houses: A (Red), B (Green), C (Yellow), D (Blue)       ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  2. UNLOCKING PAWNS                                          ║\n";
            cout << "║     • A pawn can ONLY leave base if you roll a 6             ║\n";
            cout << "║     • The 6 also counts as a move (pawn moves 6 steps)       ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  3. ROLLING THE DICE                                         ║\n";
            cout << "║     • Roll by pressing Enter                                 ║\n";
            cout << "║     • Roll a 6 → Get an EXTRA turn (roll again)              ║\n";
            cout << "║     • Roll three 6s in a row → Turn CANCELLED, all lost      ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  4. MOVEMENT                                                 ║\n";
            cout << "║     • Move pawn forward by exact dice value                  ║\n";
            cout << "║     • Must use the full roll — cannot move partial           ║\n";
            cout << "║     • Need EXACT roll to enter home (position 56)            ║\n";
            cout << "║     • Overshooting home = cannot move                        ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  5. SAFE SPOTS (*)                                           ║\n";
            cout << "║     • Marked with * on the board                             ║\n";
            cout << "║     • Pawns on safe spots CANNOT be captured                 ║\n";
            cout << "║     • Each player has one safe spot at their start           ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  6. CAPTURING (TRAPPING)                                     ║\n";
            cout << "║     • Land on opponent's pawn → They go back to base!        ║\n";
            cout << "║     • Cannot capture on safe spots                           ║\n";
            cout << "║     • Capturing gives you an EXTRA turn                      ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  7. EXTRA TURNS                                              ║\n";
            cout << "║     You get an extra turn when you:                          ║\n";
            cout << "║     • Roll a 6                                               ║\n";
            cout << "║     • Capture an opponent's pawn                             ║\n";
            cout << "║     • Move a pawn into the central home (H)                  ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  8. HOME STRETCH                                             ║\n";
            cout << "║     • After completing the outer track, enter home stretch   ║\n";
            cout << "║     • Positions 51-55 are the colored path (1,2,3,4)         ║\n";
            cout << "║     • Need exact roll to reach center H (position 56)        ║\n";
            cout << "╠══════════════════════════════════════════════════════════════╣\n";
            cout << "║  9. WINNING                                                  ║\n";
            cout << "║     • First player to get ALL 4 pawns to home WINS!          ║\n";
            cout << "║     • Game ends immediately when someone wins                ║\n";
            cout << "╚══════════════════════════════════════════════════════════════╝\n";
            
            cout << "(PRESS ENTER TO CONTINUE)\n\n";
            // Do not require cin.ignore() here because main menu already cleaned up!
            cin.get();
            cout << "==========================================================\n";
        }
        return false;
    }

    void showTitle() {
        cout << "\n";
    cout << "\n";
    cout << "                                         .-------.\n";
    cout << "   _      _  _   ____    ___            / o   o /|\n";
    cout << "  | |    | || | |  _ \\  / _ \\          /_______/o|\n";
    cout << "  | |    | || | | | | || | | |         | o   o | |\n";
    cout << "  | |___ | || |_| |_| || |_| |         |   o   |o/\n";
    cout << "  |_____| \\___/ |____/  \\___/          | o   o |/ \n";
    cout << "                                       '-------'  \n";
    cout << "\n";
    cout << "     +--------------------------------------------+\n";
    cout << "     | WELCOME TO THE ULTIMATE CONSOLE EXPERIENCE |\n";
    cout << "     +--------------------------------------------+\n";
    cout << "\n";
    cout << "       +-------------------------------------------+\n";
    cout << "       | (Made by Madhav Kohli entirely using C++) |\n";
    cout << "       +-------------------------------------------+\n\n";
    cout<<"\n\n";
    cout<<"LOADING MAIN MENU ....\n\n";
    }

    void pb(vector<string>& board, int n) {
        if (n == 2) {
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
        else if (n == 3) {
            board = {
                "  A   A     . . .     B   B ",
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
            board = {
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
        cout << "\n\nInitial board :-\n\n";
        for (string s : board) {
            cout << s << endl;
        }
    }

    // New Bulletproof Player Setup
    int askNumberOfPlayers() {
        int n;
        while (true) {
            cout << "Kindly Enter the number of players (2-4): ";
            cin >> n;

            if (cin.fail() || n < 2 || n > 4) {
                cout << "\n[!] Invalid selection. Please choose between 2 and 4.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } 
            else {
                cout << "\nThe number of players selected is " << n << "\n";
                cout << "Houses information:-\n";
                cout << "Player 1 --> House A\n";
                cout << "Player 2 --> House B\n";
                if (n >= 3) cout << "Player 3 --> House C\n";
                if (n == 4) cout << "Player 4 --> House D\n";
                
                cout << "\nPress Enter key to continue: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                
                cout << "\n";
                return n;
            }
        }
    }
};
