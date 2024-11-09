#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T> string type(T x) {
    return typeid(x).name();
}

int main() {
    string s = "Hello!";
    int i = 10;

    cout << "Here is the output of type() for a string: " << type(s) << endl;
    cout << "Here is the output of type() for an int: " << type(i) << endl;
    
    return 0;
}