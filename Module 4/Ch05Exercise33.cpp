#include <iostream>
using namespace std;

int main() {

    float a;
    float b;
    float t;

    float total = 0;
    int result = 0;

    cout << "How much time does it take for you to make your first dish? ";
    cin >> a;

    cout << "How much extra time will each subsequent dish take you to make? ";
    cin >> b;

    cout << "How much time do you have to cook? ";
    cin >> t;

    while (total < t) {
        total += a;
        a += b;
        if (total <= t) {
            result += 1;
        }
    }

    cout << "You can prepare a total of " << result << " dishes." << endl;
    system("pause");

    return 0;
    
}
