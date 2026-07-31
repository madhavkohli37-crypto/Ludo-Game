#include <iostream>
#include <limits>
#include "turn.h"
#include "intro.h"
#include "ai.h"

using namespace std;

// Bulletproof Main Menu function
int showMainMenu() {
    int choice;
    while (true) {
        cout << "╔═══════════════════════════════════════════════╗\n";
        cout << "║                  MAIN MENU                    ║\n";
        cout << "╠═══════════════════════════════════════════════╣\n";
        cout << "║  [1] Start New Game                           ║\n";
        cout << "║  [2] View Rule Book & Start Game              ║\n";
        cout << "║  [3] Exit Game                                ║\n";
        cout << "╚═══════════════════════════════════════════════╝\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3) {
            cout << "\n[!] Invalid selection. Please enter 1, 2, or 3.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return choice;
        }
    }
}

int main() {
    srand(time(0));

    bool winner = false;
    int currentPlayerIdx = 0;
    int numPlayers;
    int numHuman;  

    vector<string> board;
    welcome w;
    
    w.showTitle();
    delay(2000);
    int menuChoice = showMainMenu();
    
    if (menuChoice == 3) {
        cout << "\n>>> Exiting Game. Goodbye! <<<\n";
        return 0;
    } 
    else if (menuChoice == 2) {
        w.fun(2);
    }
    
    w.text();
    
    // Gets players safely
    numPlayers = w.askNumberOfPlayers();

    // Bulletproof Human Player input
    cout << "\nHow many HUMAN players? (1-" << numPlayers << "): ";
    while (true) {
        cin >> numHuman;
        if (cin.fail() || numHuman < 1 || numHuman > numPlayers) {
            cout << "[!] Invalid! Enter a number between 1 and " << numPlayers << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    bool isAI[4] = {false, false, false, false};
    AI ai;
    for (int i = numHuman; i < numPlayers; i++) {
        isAI[i] = true;
    }

    cout << "\n--- Player Setup ---\n";
    for (int i = 0; i < numPlayers; i++) {
        cout << "Player " << (char)('A' + i);
        if (isAI[i]) cout << " [AI]";
        else cout << " [Human]";
        cout << "\n";
    }
    cout << "--------------------\n";

    w.pb(board, numPlayers);

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
        bool earnedExtra = true;

        while (earnedExtra && !winner) {
            earnedExtra = false;

            cout << "\n--------------------------------\n";
            cout << "PLAYER " << p.house << "'s TURN";
            if (isAI[currentPlayerIdx]) { cout << " [AI]"; }
            cout << "\n--------------------------------\n";

            logic.showStatus(players, numPlayers);
            vector<int> rolls;
            
            if (isAI[currentPlayerIdx]) {
                rolls = turnAI(currentPlayerIdx + 1);
                delay(2000);
            }
            else {
                rolls = turn(currentPlayerIdx + 1);
            }

            if (rolls.empty()) {
                cout << "\nTurn ended (3 sixes).\n";
                break;
            }

            cout << "\nRolls: ";
            for (int r : rolls) cout << r << " ";
            cout << "\n";
            
            for (int dice : rolls) {
                vector<int> valid = logic.getValidPawns(p, dice);

                if (valid.empty()) {
                    cout << "\nNo valid moves for " << dice << ".\n";
                    delay(1000);
                    continue;
                }

                int choice;
                if (isAI[currentPlayerIdx]) {
                    cout << "\n[AI is thinking...]\n";
                    delay(2000);
                    choice = ai.choosePawn(p, valid, dice, players, numPlayers, logic);
                }
                else {
                    cout << "\nValid pawns: ";
                    for (int id : valid) cout << (id + 1) << " ";
                    cout << "\nSelect pawn: ";

                    // Bulletproof Pawn Selection
                    while (true) {
                        cin >> choice;
                        if (cin.fail()) {
                            cout << "[!] Invalid input! Please enter a number: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                        
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        choice--; 

                        bool ok = false;
                        for (int id : valid) {
                            if (id == choice) ok = true;
                        }
                        
                        if (!ok) {
                            cout << "[!] Invalid pawn! Please select from valid pawns: ";
                        } else {
                            break; 
                        }
                    }
                }
                
                bool extra = logic.movePawn(players, numPlayers, currentPlayerIdx, choice, dice);
                logic.showStatus(players, numPlayers);
                   logic.askAndShowBoard(board, players, numPlayers);
                if (extra) {
                    earnedExtra = true;
                    cout << "\n*** Extra turn earned! ***\n";
                }
            }
            
            if (p.pawnsAtHome() == 4) {
                winner = true;
                cout << "\n\n>>> PLAYER " << p.house;
                if (isAI[currentPlayerIdx]) cout << " [AI]";
                cout << " WINS! <<<\n";
                break;
            }
        }

        if (!winner) {
            currentPlayerIdx = (currentPlayerIdx + 1) % numPlayers;
        }
    }

    cout << "\n========== GAME OVER ==========\n";
    cout << "THANKS FOR PLAYING\n";
    cout << "HOPE YOU ENJOYED and WE WISH TO SEE YOU AGAIN !\n\n";
    cout << "GOOD BYE ! \n";
    return 0;
}
