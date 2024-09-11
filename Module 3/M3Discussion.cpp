/* 
This is a simplified version of the "FizzBuzz" problem,
which takes in a number and outputs a word if it is divisible by 3 and/or 5.
If the number is not divisible by 3 or 5, it outputs the number itself.
*/

#include <iostream>
using namespace std;

int main {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (num % 5 == 0 && num % 3 == 0) {
        cout << "FizzBuzz";
    } 
    else if (num % 3 == 0) {
        cout << "Fizz";
    } 
    else if (num % 5 == 0):
        cout << "Buzz";
    
    else {
        cout << num;
    }
    return 0;
}