#include <iostream>
#include<vector>
#include<ctime>
#include<cstring>
#include<climits>
using namespace std; 
void delay(int ms) {
    for (volatile long long i = 0; i < ms * 800000LL; i++);
}
vector<int>F(int currentplayer,int t6,vector<int>&numbers) {
    cout << "Press Enter to roll the dice --> ";
    cin.get();
    int diceRoll=(rand()%6)+1;
    numbers.push_back(diceRoll);
    cout << "\nPlayer " << currentplayer << " rolled a " << diceRoll << "!\n";
    if(diceRoll==6 and t6<2) {
        t6++;
        cout<<"You got a 6 so you can roll again\n";
        F(currentplayer,t6,numbers);
    }
    else if(diceRoll==6) {
        cout<<"you got 3 6's in a row hence your turn is terminated!\n";
        numbers.clear();
    }
        return numbers;
}
vector<int> turn(int currentplayer) {
    int t6=0;
vector<int>numbers;
    return F(currentplayer,t6,numbers);
}
vector<int> turnAI(int currentplayer) {
    int t6 = 0;
    vector<int> numbers;
    
    while (true) {
        int diceRoll = (rand() % 6) + 1;
        numbers.push_back(diceRoll);
        cout << "\nAI Player " << currentplayer << " rolled a " << diceRoll << "!\n";
        if (diceRoll == 6 && t6 < 2) {
            t6++;
            cout << "AI got a 6! Rolling again...\n";
            delay(1000);
        }
        else if (diceRoll == 6) {
            cout << "AI got 3 sixes in a row! Turn terminated!\n";
            numbers.clear();
            break;
        }
        else {
            break;
        }
    }
    return numbers;
}
