#include<iostream>
#include<vector>
#include<map>
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
    "  A   A     . 2 .     B   B ",
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
    "  D   D     . 4 .     C   C ",
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
            cout<<"Kindly start the game again and make a valid selection for number of players b/w 1&4\n";
            return false;
        }
        cout<<"Press Enter key to continue :";
        cin.get();
        cout<<"\n";
        return true;
    }
};
