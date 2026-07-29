#include"turn.h"
#include "intro.h"
#include "ai.h"

int main() {
    srand(time(0));

    bool winner = false;
    int currentPlayerIdx = 0;
    int numPlayers;
    int numHuman;  // Number of human players

    vector<string> board;
    welcome w;
    w.showTitle();

    // ============ MAIN MENU ============
    cout << "============================\n";
    cout << "        MAIN MENU\n";
    cout << "============================\n\n";
    cout << "Press 1 to Start New Game\n";
    cout << "Press 2 to View Rule Book and Start New Game\n";
    cout << "Press 3 to Exit\n\n";
    cout << "Enter your choice: ";
    
    int num;
    cin >> num;
    cin.get();
    
    if (w.fun(num)) {
        return 0;
    }
    w.text();

    // ============ PLAYER SETUP ============
    w.th();
    cin >> numPlayers;
    cin.get();

    if (w.th2(numPlayers) == false) {
        cout << "\nGame ends. \nGOOD BYE !\n\n";
        return 0;
    }

    // NEW: Ask how many are human
    cout << "\nHow many HUMAN players? (1-" << numPlayers << "): ";
    cin >> numHuman;
    cin.get();
    
    while (numHuman < 1 || numHuman > numPlayers) {
        cout << "Invalid! Enter 1 to " << numPlayers << ": ";
        cin >> numHuman;
        cin.get();
    }

    // Setup AI flags
    bool isAI[4] = {false, false, false, false};
    AI ai;
    
    // First 'numHuman' players are human, rest are AI
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

    // ============ MAIN GAME LOOP ============
    while (!winner) {
        Player &p = players[currentPlayerIdx];
        bool earnedExtra = true;

        while (earnedExtra && !winner) {
            earnedExtra = false;

            cout << "\n--------------------------------\n";
            cout << "PLAYER " << p.house << "'s TURN";
            if (isAI[currentPlayerIdx]) {cout << " [AI]";
            }
            cout << "\n--------------------------------\n";

            logic.showStatus(players, numPlayers);
            // ============ ROLL DICE ============
            vector<int> rolls;
            
            if (isAI[currentPlayerIdx]) {
                // AI rolls automatically
                rolls = turnAI(currentPlayerIdx + 1);
                delay(2000);
            }
            else {
                // Human presses Enter to roll
                rolls = turn(currentPlayerIdx + 1);
            }

            if (rolls.empty()) {
                cout << "\nTurn ended (3 sixes).\n";
                break;
            }

            cout << "\nRolls: ";
            for (int r : rolls) cout << r << " ";
            cout << "\n";

            // Process each roll
            for (int dice : rolls) {
                vector<int> valid = logic.getValidPawns(p, dice);

                if (valid.empty()) {
                    cout << "\nNo valid moves for " << dice << ".\n";
                    delay(1000);
                    continue;
                }

                int choice;

                // ============ AI DECISION ============
                if (isAI[currentPlayerIdx]) {
                    cout << "\n[AI is thinking...]\n";
                    delay(2000);
                    // Small delay for realism
                    choice = ai.choosePawn(p, valid, dice, players, numPlayers, logic);
                }
                // ============ HUMAN DECISION ============
                else {
                    cout << "\nValid pawns: ";
                    for (int id : valid) cout << (id + 1) << " ";
                    cout << "\nSelect pawn: ";

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
                }

                // Move pawn
                bool extra = logic.movePawn(players, numPlayers, currentPlayerIdx, choice, dice);
                logic.showStatus(players, numPlayers);
                // Only ask human to show board
                   logic.askAndShowBoard(board, players, numPlayers);
                if (extra) {
                    earnedExtra = true;
                    cout << "\n*** Extra turn earned! ***\n";
                }
            }

            // Check win
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
