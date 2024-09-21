#include <iostream>

using namespace std;

int main() {
    int n = 1;
    int old = 1;
    int older = 0;

    while (n <= 10000) {
        cout << n << endl;
        n = old + older;
        older = old;
        old = n;
    }
    
    return 0;
}
