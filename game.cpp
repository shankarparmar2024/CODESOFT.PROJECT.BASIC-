#include <iostream>   // for input/output
#include <cstdlib>    // for rand() and srand()
#include <ctime>      // for time()

using namespace std;

int main() {

    // Step 1: Initialize random seed (so number changes every run)
    srand(time(0));

    // Step 2: Generate random number between 1 to 100
    int randomNumber = rand() % 100 + 1;

    int guess;  // variable to store user guess

    cout << "🎮 Welcome to Number Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    // Step 3: Loop until user guesses correctly
    while (true) {

        cout << "Enter your guess: ";
        cin >> guess;

        // Step 4: Check conditions
        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            // Correct guess
            cout << "🎉 Correct! You guessed the number!" << endl;
            break; // exit loop
        }
    }

    return 0;
}