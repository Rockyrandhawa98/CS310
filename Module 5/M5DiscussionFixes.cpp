//
// Original created by Javier on 9/25/2024.
//
#include <iostream>
#include <string>

using namespace std;

// Function definitions

// Returns the user's name
string getName() {
    string name;
    cout << "Enter your first name: ";
    cin >> name;  
    return name;
}

// Returns the user's username
string getUsername() {
    string username;
    cout << "Enter your username: ";
    cin >> username;
    return username;
}

// Returns the user's password
string getPassword() {
    string password;
    cout << "Enter your password: ";
    cin >> password;
    return password;
}

int main() {
    // Call functions
    string name = getName();
    string username = getUsername();
    string password = getPassword();

    // Output the account details
    cout << "\nAccount successfully created!\n";
    cout << "Name: " << name << endl;
    cout << "Username: " << username << endl;

    return 0;
}