#include<iostream>
#include<vector>
#include<map>
using namespace std;
class welcome{
    public:
    void text() {
            cout << "\n";
    cout << "+-------------------------------------------------------------+\n";
    cout << "|                  PRO TIPS & STRATEGY                          |\n";
    cout << "+-------------------------------------------------------------+\n";
    cout << "|                                                             |\n";
    cout << "|  [1] UNLOCK EARLY                                           |\n";
    cout << "|      Unlock multiple pawns to increase movement options.     |\n";
    cout << "|                                                             |\n";
    cout << "|  [2] USE SAFE CELLS (*)                                     |\n";
    cout << "|      Protect your pawns from capture on Safe Cells.        |\n";
    cout << "|                                                             |\n";
    cout << "|  [3] CAPTURE OPPONENTS                                      |\n";
    cout << "|      Send them back to base and earn an extra turn!        |\n";
    cout << "|                                                             |\n";
    cout << "|  [4] AVOID EXPOSURE                                         |\n";
    cout << "|      Don't leave pawns vulnerable near enemies.            |\n";
    cout << "|                                                             |\n";
    cout << "|  [5] PLAN AHEAD                                             |\n";
    cout << "|      Spread pawns instead of moving the same one always.   |\n";
    cout << "|                                                             |\n";
    cout << "|  [6] EXTRA TURNS                                            |\n";
    cout << "|      Rolling 6, reaching HOME, or capturing = extra roll!  |\n";
    cout << "|                                                             |\n";
    cout << "|  [7] EXACT ROLL FOR HOME                                    |\n";
    cout << "|      Overshooting means you cannot move that turn.         |\n";
    cout << "|                                                             |\n";
    cout << "+-------------------------------------------------------------+\n";
    cout << "|              Good Luck & Have Fun!                          |\n";
    cout << "+-------------------------------------------------------------+\n";
    cout << "\n        >>>  LET THE GAME BEGIN!  <<<\n\n";
cout<<"(PRESS ENTER TO CONTINUE)\n\n";
cin.get();
    }
    bool fun(int n) {
        if(n==1) {
            return false;
        }
        if(n==2) {
              cout << "\n";
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║                    LUDO RULEBOOK                             ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  1. SETUP                                                  ║\n";
    cout << "║     • 2-4 players can play                                 ║\n";
    cout << "║     • Each player gets 4 pawns in their base               ║\n";
    cout << "║     • Houses: A (Red), B (Green), C (Yellow), D (Blue)     ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  2. UNLOCKING PAWNS                                        ║\n";
    cout << "║     • A pawn can ONLY leave base if you roll a 6           ║\n";
    cout << "║     • The 6 also counts as a move (pawn moves 6 steps)     ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  3. ROLLING THE DICE                                       ║\n";
    cout << "║     • Roll by pressing Enter                               ║\n";
    cout << "║     • Roll a 6 → Get an EXTRA turn (roll again)            ║\n";
    cout << "║     • Roll three 6s in a row → Turn CANCELLED, all lost    ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  4. MOVEMENT                                               ║\n";
    cout << "║     • Move pawn forward by exact dice value                ║\n";
    cout << "║     • Must use the full roll — cannot move partial          ║\n";
    cout << "║     • Need EXACT roll to enter home (position 56)          ║\n";
    cout << "║     • Overshooting home = cannot move                      ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  5. SAFE SPOTS (*)                                         ║\n";
    cout << "║     • Marked with * on the board                           ║\n";
    cout << "║     • Pawns on safe spots CANNOT be captured               ║\n";
    cout << "║     • Each player has one safe spot at their start         ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  6. CAPTURING (TRAPPING)                                   ║\n";
    cout << "║     • Land on opponent's pawn → They go back to base!      ║\n";
    cout << "║     • Cannot capture on safe spots                         ║\n";
    cout << "║     • Capturing gives you an EXTRA turn                    ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  7. EXTRA TURNS                                            ║\n";
    cout << "║     You get an extra turn when you:                        ║\n";
    cout << "║     • Roll a 6                                             ║\n";
    cout << "║     • Capture an opponent's pawn                           ║\n";
    cout << "║     • Move a pawn into the central home (H)                ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  8. HOME STRETCH                                           ║\n";
    cout << "║     • After completing the outer track, enter home stretch  ║\n";
    cout << "║     • Positions 51-55 are the colored path (1,2,3,4)       ║\n";
    cout << "║     • Need exact roll to reach center H (position 56)      ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    cout << "║  9. WINNING                                                ║\n";
    cout << "║     • First player to get ALL 4 pawns to home WINS!        ║\n";
    cout << "║     • Game ends immediately when someone wins              ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n";
    cout<<"(PRESS ENTER TO CONTINUE)\n\n";
cin.get();
cout << "==========================================================\n";
return false;
        }
        if(n==3) {
            cout<<"You choose 3-Exit , Hence\n";
    cout<<" =======GAME ENDS=====\n\nGOOD BYE !\n\n";
    return true;
        }
        else {
            cout<<"Invalid selection , Please Try Again. \n\n\n";
            cout<<"------X ABORTING TERMINAL X------\n";
        }
        return true;
    }
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
        cout<<"(Made by Madhav Kohli entirely using C++)\n\n";
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
            cout<<"Kindly start the game again and make a valid selection for number of players b/w 2 & 4\n";
            return false;
        }
        cout<<"Press Enter key to continue :";
        cin.get();
        cout<<"\n";
        return true;
    }
};
