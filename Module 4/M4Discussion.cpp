#include <iostream>
#include <cstdlib>

using namespace standard;

int main() {
    // Generates random seed so the rand() function can select a random number each time, the error isn't here
    srand((unsigned) time(NULL)); 
    int target = rand() % 100;
    int guess;

    while (guess != target) {

        cout << "Guess a number, 1 through 100. Enter '-1' to quit. " << endl;
        cin >> guess;

        if (guess == target || -1) {
            break;
        }
        else if (guess > target) {
            cout << "\nThat guess is too high. Try again!" << endl;
        }
        else {
            cout << "\nThat guess is too low. Try again!" << endl;
        }
        }
    
    cout << endl;
    if (guess == target) {
        cout << "Congratulations, you correctly guessed the number " << target << "!" << endl;
    }
    else {
        cout << "Nice try, the correct number was " << target << "!" << endl;
    }

    return 0;        
}
