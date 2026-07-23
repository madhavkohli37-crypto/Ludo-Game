#include "intro.h"
#include "gamelogic.h"

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
