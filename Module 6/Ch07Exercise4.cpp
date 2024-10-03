#include <iostream>
#include <string>

using namespace std;

bool isVowel (char& letter) {
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < vowels.size(); i++) {
        if (letter == vowels[i]) {
            return true;
        }
    }
    return false;
}

string substr (string& inputString) {
    string withoutVowels = "";

    for (int i = 0; i < inputString.size(); i++) {
        if (isVowel(inputString[i]) == false) {
            withoutVowels += inputString[i];
        }
    }
    return withoutVowels;
}

int main() {
    string word;
    cout << "\nEnter a string: ";
    cin >> word;

    string res = substr(word);

    cout << "\nThe string without vowels is " << res << "." << endl;

    return 0;
}
