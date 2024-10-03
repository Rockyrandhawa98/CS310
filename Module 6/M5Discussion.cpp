#include <iostream>
using namespace std;

Enum NumberThresholds { Low=25, High=75 };

int main() {
    int number;
    cout << "Pick a number: " << endl;
    cin >> number;

    if (number <= Low) {
        cout << "That's a low number." << endl;
    }
    elif (number < High) {
        cout << "Thats a medium number." << endl;
    }
    else {
        cout << "That's a high number." << endl;
    }

    return 0;
}