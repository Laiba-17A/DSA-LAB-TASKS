#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame(int secret, int currentPlayer) {
    int userGuess;
    cout << "Player " << currentPlayer << ", enter your guess: ";
    cin >> userGuess;

    if (userGuess == secret) {
        cout << "Player " << currentPlayer << " guessed the correct number" << endl;
        return;
    } 
    else {
        if (userGuess < secret)
            cout << "Too low" << endl;
        else
            cout << "Too high" << endl;

        if (currentPlayer == 1)
            currentPlayer = 2;
        else
            currentPlayer = 1;

        playGame(secret, currentPlayer);
    }
}

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    playGame(secretNumber, 1);
    return 0;
}

