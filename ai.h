#include"gamelogic.h"
// ============ AI CLASS ============
class AI {
public:
    int choosePawn(Player &aiPlayer, vector<int> validPawns, int dice, 
                   Player players[], int numPlayers, GameLogic &logic) {
        
        // Priority 1: Unlock pawn (if rolled 6 and have base pawns)
        if (dice == 6) {
            for (int id : validPawns) {
                if (aiPlayer.pawns[id].position == -1) {
                    cout << "AI chooses to unlock Pawn " << (id + 1) << "\n";
                    delay(1000);
                    return id;
                }
            }
        }
        
        // Priority 2: Capture opponent if possible
        for (int id : validPawns) {
            if (canCapture(aiPlayer, id, dice, players, numPlayers, logic)) {
                cout << "AI chooses to capture with Pawn " << (id + 1) << "\n";
                delay(1000);
                return id;
            }
        }
        
        // Priority 3: Reach home with exact roll
        for (int id : validPawns) {
            if (aiPlayer.pawns[id].position + dice == 56) {
                cout << "AI chooses to reach home with Pawn " << (id + 1) << "\n";
                delay(1000);
                return id;
            }
        }
        
        // Priority 4: Enter home stretch
        for (int id : validPawns) {
            int newPos = aiPlayer.pawns[id].position + dice;
            if (newPos >= 51 && newPos < 56) {
                cout << "AI enters home stretch with Pawn " << (id + 1) << "\n";
                delay(1000);
                return id;
            }
        }
        
        // Priority 5: Move pawn closest to home (highest position)
        int bestPawn = validPawns[0];
        int maxPos = aiPlayer.pawns[bestPawn].position;
        
        for (int id : validPawns) {
            if (aiPlayer.pawns[id].position > maxPos) {
                maxPos = aiPlayer.pawns[id].position;
                bestPawn = id;
            }
        }
        
        cout << "AI chooses Pawn " << (bestPawn + 1) << " (furthest advanced)\n";
        delay(1000);
        return bestPawn;
    }
    
private:
    bool canCapture(Player &aiPlayer, int pawnId, int dice, 
                    Player players[], int numPlayers, GameLogic &logic) {
        
        Pawn &p = aiPlayer.pawns[pawnId];
        if (p.position == -1) return false;
        
        int newPos = p.position + dice;
        if (newPos > 50) return false;
        
        int absPos = logic.getAbsPos(aiPlayer, newPos);
        if (logic.isSafe(absPos)) return false;
        
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].house == aiPlayer.house) continue;
            
            for (int j = 0; j < 4; j++) {
                Pawn &enemy = players[i].pawns[j];
                if (enemy.position >= 0 && enemy.position <= 50 && !enemy.isHome) {
                    int enemyAbsPos = logic.getAbsPos(players[i], enemy.position);
                    if (enemyAbsPos == absPos) return true;
                }
            }
        }
        return false;
    }
};
