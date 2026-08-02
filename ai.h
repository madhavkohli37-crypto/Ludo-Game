#include "gamelogic.h"

class AI {
public:
    int choosePawn(Player &aiPlayer, vector<int> validPawns, int dice, 
                   Player players[], int numPlayers, GameLogic &logic) {
        if (dice == 6) {
            for (int id : validPawns) {
                if (aiPlayer.pawns[id].position == -1) {
                    cout << "🤖 AI tactical maneuver: Unlocking Pawn " << (id + 1) << "! Watch and learn, human. ♟️ 🔥\n";
                    delay(2000);
                    cout << "🤖 AI: 'Should I lower the difficulty setting for you? Oh wait, there is no lower setting than your current gameplay.' 📉 🤡\n";
                    delay(2000);
                    return id;
                }
            }
        }
        for (int id : validPawns) {
            if (canCapture(aiPlayer, id, dice, players, numPlayers, logic)) {
                cout << "🤖 AI target locked! Pawn " << (id + 1) << " is coming in for a ruthless execution! 🎯 💀 🔥\n";
                delay(1000);
                cout<<"Look at that momentum! Too bad you can't relate.' 🏃💨🏁✨\n";
                delay(1000);
                cout << "🤖 AI: 'Even a random number generator with a dead battery makes better tactical choices than you.' 🎲 🔋 ❌\n";
                delay(1500);
                return id;
            }
        }
        for (int id : validPawns) {
            if (aiPlayer.pawns[id].position + dice == 56) {
                cout << "🤖 AI victory lap! Pawn " << (id + 1) << " safely reaches home. One step closer to total domination! 🏆 🚀 🔥\n";
                delay(2000);
                cout << "🤖 AI: 'I ran a complete simulation of this game, and the only variable I couldn't account for was how historically bad your moves would be.' 💀 📉 🔥\n";
                delay(2000);
                return id;
            }
        }
        for (int id : validPawns) {
            int newPos = aiPlayer.pawns[id].position + dice;
            if (newPos >= 51 && newPos < 56) {
                cout << "🤖 AI: 'Pawn " << (id + 1) << " is waltzing into the home stretch. Look at that momentum! Too bad you can't relate.' 🏃 💨 🏁 ✨ \n";
                delay(2000);
                cout << "🤖 AI: 'Is your keyboard broken, or are you just naturally this bad at making decisions?' ⌨️ 💥\n";
                delay(2000);
                return id;
            }
        }
        int bestPawn = validPawns[0];
        int maxPos = aiPlayer.pawns[bestPawn].position;
        
        for (int id : validPawns) {
            if (aiPlayer.pawns[id].position > maxPos) {
                maxPos = aiPlayer.pawns[id].position;
                bestPawn = id;
            }
        }
        
        cout << "🤖 AI flex: Choosing Pawn " << (bestPawn + 1) << " (furthest advanced). Gotta widen the gap while you're still stuck trying to figure out the rules! 📈 🚀 ✨\n";
        delay(2500);
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
