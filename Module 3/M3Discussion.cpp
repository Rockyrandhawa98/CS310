/* 
This is a simplified version of the "FizzBuzz" problem,
which takes in a number and outputs a word based on its divisors: 3 and 5.
If there is no valid divisor, it outputs the number itself.
*/

#include <iostream>
using namespace std;

int main {
    int num ;
    cout << "Enter an integer: " ;
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