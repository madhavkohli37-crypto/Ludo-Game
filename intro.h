#include<iostream>
#include<vector>
#include<map>
using namespace std;
class welcome{
    public:
    void text() {
        cout << "GAME TIPS\n";
cout << "---------\n";
cout << "1. Unlock multiple pawns early to increase your\n";
cout << "   movement options.\n\n";

cout << "2. Use Safe Cells (*) whenever possible to\n";
cout << "   protect your pawns.\n\n";

cout << "3. Capture opponents whenever you get the\n";
cout << "   opportunity to slow their progress.\n\n";

cout << "4. Avoid leaving a single pawn exposed near\n";
cout << "   enemy pawns unless it is on a Safe Cell.\n\n";

cout << "5. Plan your moves carefully instead of moving\n";
cout << "   the same pawn every turn.\n\n";

cout << "6. Remember that reaching HOME and capturing\n";
cout << "   an opponent both grant an extra dice roll.\n\n";

cout << "7. Always keep an eye on the exact roll needed\n";
cout << "   to reach HOME.\n\n";
cout<<"All the best to the players !\n\n";
cout<<"/-------------------------------------/\n\n";
cout<<"LET THE GAME BEGIN !\n\n";
cout<<"(PRESS ENTER TO CONTINUE)\n\n";
cin.get();
    }
    bool fun(int n) {
        if(n==1) {
            return false;
        }
        if(n==2) {
            cout << "==========================================================\n";
cout << "                    LUDO RULE BOOK\n";
cout << "==========================================================\n\n";

cout << "OBJECTIVE\n";
cout << "---------\n";
cout << "Be the first player to move all 4 of your pawns\n";
cout << "from your house to HOME.\n\n";

cout << "NUMBER OF PLAYERS\n";
cout << "-----------------\n";
cout << "This game supports:\n";
cout << "-> 2 Players\n";
cout << "-> 3 Players\n";
cout << "-> 4 Players\n\n";

cout << "PAWNS\n";
cout << "-----\n";
cout << "Each player starts with 4 pawns inside their house.\n\n";

cout << "ROLLING THE DICE\n";
cout << "----------------\n";
cout << "A standard six-sided dice is used.\n\n";

cout << "UNLOCKING A PAWN\n";
cout << "----------------\n";
cout << "A pawn can leave the house only after rolling a 6.\n\n";

cout << "MOVEMENT\n";
cout << "--------\n";
cout << "Move one pawn forward according to the dice value.\n\n";
cout << "If multiple pawns can move,\n";
cout << "the player chooses which pawn to move.\n\n";

cout << "MULTIPLE ROLLS\n";
cout << "--------------\n";
cout << "Rolling a 6 grants an extra dice roll.\n\n";
cout << "If a player rolls three consecutive 6s,\n";
cout << "the entire turn is cancelled.\n\n";

cout << "SAFE CELLS\n";
cout << "----------\n";
cout << "Cells marked with '*' are Safe Cells.\n\n";
cout << "A pawn standing on a Safe Cell cannot be captured.\n\n";

cout << "CAPTURING\n";
cout << "---------\n";
cout << "If your pawn lands exactly on an opponent's pawn\n";
cout << "that is NOT on a Safe Cell,\n\n";
cout << "-> The opponent's pawn returns to its house.\n";
cout << "-> You receive an extra turn.\n\n";

cout << "HOME STRETCH\n";
cout << "------------\n";
cout << "After completing one full round,\n";
cout << "the pawn enters its Home Stretch.\n\n";
cout << "Only that player's pawns may enter this path.\n\n";

cout << "REACHING HOME\n";
cout << "-------------\n";
cout << "A pawn reaches HOME only by obtaining\n";
cout << "the exact dice value.\n\n";
cout << "If the dice exceeds the remaining distance,\n";
cout << "the pawn does not move.\n\n";
cout << "Reaching HOME rewards the player with\n";
cout << "one extra dice roll.\n\n";

cout << "WINNER\n";
cout << "------\n";
cout << "The first player to bring all 4 pawns\n";
cout << "to HOME wins the game.\n\n";

cout << "BOARD LEGEND\n";
cout << "------------\n";
cout << "A B C D  -> Player Houses\n";
cout << "1 2 3 4  -> Player Paths\n";
cout << "H        -> Home Path\n";
cout << "*        -> Safe Cell\n";
cout << ".        -> Normal Cell\n\n";

cout << "==========================================================\n";
cout << "(Press ENTER to continue...)\n";
cin.get();
cout << "==========================================================\n";
return false;
        }
        if(n==3) {
            cout<<"You choose 3-Exit , Hence\n";
    cout<<" =======GAME ENDS=====\n";
    return true;
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
