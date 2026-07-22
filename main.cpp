#include "intro.h"
#include"gamelogic.h"
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
        cout << "\n\nGame ends\n";
        return 0;
    }

    w.pb(board, numPlayers);

    cout << "\n\nCore Gameplay Rules :-\n";
    cout << "1). Unlocking Pawns: A pawn can only leave its base and enter the active track if you roll a 6.\n";
    cout << "2). Extra Turns: You get an extra dice roll if :-\n";
    cout << "   a). You roll a 6.\n";
    cout << "   b). You capture and send an opponent's pawn back to its base.\n";
    cout << "   c). You successfully move a pawn into the central home (H).\n";
    cout << "3). Movement: Move an active pawn forward by the exact number shown on the dice.\n";
    cout << "4). Capturing: Landing on an opponent's pawn returns it to their base—unless they are standing on a safe spot (*).\n\n";

    Player players[4] = {
        Player('A', 0),
        Player('B', 13),
        Player('C', 26),
        Player('D', 39)
    };

    GameLogic logic;

    cout << "\n\n========== GAME START ==========\n";

    while (!winner) {
        Player &p = players[currentPlayerIdx];

        cout << "\n--------------------------------\n";
        cout << "Player " << p.house << "'s turn:\n";
        p.showPawns();

        vector<int> rolls = turn(currentPlayerIdx + 1);

        if (rolls.empty()) {
            cout << "\nTurn terminated (3 sixes).\n";
        }
        else {
            cout << "\nYour rolls: ";
            for (int r : rolls) cout << r << " ";
            cout << "\n";

            for (int dice : rolls) {
                vector<int> valid = logic.getValidPawns(p, dice);

                if (valid.empty()) {
                    cout << "\nNo valid moves for " << dice << ". Skip.\n";
                    continue;
                }

                cout << "\nValid pawns for " << dice << ": ";
                for (int id : valid) cout << (id + 1) << " ";
                cout << "\n";

                int choice;
                bool ok = false;
                while (!ok) {
                    cout << "Select pawn: ";
                    cin >> choice;
                    cin.ignore();
                    choice--;

                    for (int id : valid) {
                        if (id == choice) {
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) cout << "Invalid! Try again.\n";
                }

                bool extra = logic.movePawn(players, numPlayers, currentPlayerIdx, choice, dice);

                // ASK TO SHOW BOARD AFTER EVERY MOVE
                logic.askAndShowBoard(players, numPlayers, board);

                p.showPawns();

                if (extra) {
                    cout << "Extra turn earned!\n";
                }
            }
        }

        if (p.pawnsAtHome() == 4) {
            winner = true;
            cout << "\n\nPLAYER " << p.house << " WINS!\n";
        }

        currentPlayerIdx = (currentPlayerIdx + 1) % numPlayers;
    }

    cout << "\n\n========== GAME OVER ==========\n";
    cout<< "THANKS FOR PLAYING!";

    return 0;
}
