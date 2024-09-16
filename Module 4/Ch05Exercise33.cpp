#include <iostream>
using namespace std;

int main() {

    float a;
    float b;
    float t;

    float total = 0;
    int result = 0;

    cout << "How many minutes does it take for you to make your first dish? ";
    cin >> a;

    cout << "How many extra minutes will each subsequent dish take you to make? ";
    cin >> b;

    cout << "How many minutes do you have to cook? ";
    cin >> t;

    while (total < t) {
        total += a;
        a += b;
        if (total <= t) {
            result += 1;
        }
    }

    cout << "You can prepare a total of " << result << " dishes in " << t << " minutes." << endl;
    system("pause");

    return 0;
    
}
