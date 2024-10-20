#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

class BankAccount {
    private:
        static int incrementingAccountNumber;
        int accountNumber;
        string accountHolderName;
        string accountType;
        double balance;
        double interestRate; // stored as decimal value
    
    public:

        // set methods
        void setAccountHolderName(string accountHolderName) {
            this->accountHolderName = accountHolderName;
            cout << "The account owner's name is now " << this->accountHolderName << "." << endl;
        }
        void setAccountType(string accountType) {
            if (accountType == "Checking" || accountType == "Savings") {
                this->accountType = accountType;
                cout << "The account is now a " << this->accountType << " Account." << endl;
            }
            else {
                cout << "Invalid account type. Choose either a 'Checking' or 'Savings' account." << endl;
            }
        }
        void setBalance(double balance) {
            this->balance = balance;
            cout << fixed << setprecision(2);
            cout << "The account's balance is now $" << this->balance << "." << endl;
        }
        void setInterestRate(double interestRate) {
            this->interestRate = interestRate;
            cout << fixed << setprecision(3);
            cout << "The account's interest rate is now " << this->interestRate << "%" << endl;
        }

        // get methods
        int getAccountNumber() {
            return this->accountNumber;
        }
        string getAccountHolderName() {
            return this->accountHolderName;
        }
        string getAccountType() {
            return this->accountType;
        }
        double getBalance() {
            return this->balance;
        }
        double getInterestRate() {
            return this->interestRate;
        }

        // desposit and withdraw methods
        void deposit(double value) {
            this->balance += value;
            cout << fixed << setprecision(2);
            cout << "$" << value  << " has been deposited into " << this->accountHolderName << "'s " \
            << this->accountType << " Account." << endl;
            cout << "Account balance is now $" << this->balance << ".\n" << endl;
        }
        void withdraw(double value) {
            cout << fixed << setprecision(2);
            if (value <= this->balance) {
                this->balance -= value;
                cout << "$" << value << " has been withdrawn from " << this->accountHolderName << "'s " \
                << this->accountType << " Account." << endl;
                cout << "Account balance is now $" << this->balance << ".\n" << endl;
            }
            else {
                cout << "There are not enough funds to withdraw $" << value << " from " \
                << this->accountHolderName << "'s Account. The current balance is $" << this->balance << "." << endl;
            }
        }


        // Constructors
        BankAccount (){
            incrementingAccountNumber++;
            this->accountNumber = incrementingAccountNumber;
        }
        BankAccount (string accountHolderName) {
            incrementingAccountNumber++;
            this->accountNumber = incrementingAccountNumber;
            this->accountHolderName = accountHolderName;
        }
        BankAccount (string accountHolderName, string accountType, double balance, double interestRate) {
            incrementingAccountNumber++;
            this->accountNumber = incrementingAccountNumber;
            this->accountHolderName = accountHolderName;
            this->accountType = accountType;
            this->balance = balance;
            this->interestRate = interestRate;
        }

};


int BankAccount::incrementingAccountNumber = 0;


int main() {
    // declaring an array of 10 BankAccount classes, iterating over the array to show each account number
    const int NUMBER_OF_ACCOUNTS = 10;
    BankAccount accounts[NUMBER_OF_ACCOUNTS];

    for (int i = 0; i < NUMBER_OF_ACCOUNTS; i++) {
        cout << "Account Number: " << accounts[i].getAccountNumber() << endl;
    }
    cout << "----------------------------------------------" << endl;

    // demonstrating the methods of the BankAccounts class
    accounts[0].setAccountHolderName("Rocky Randhawa");
    accounts[0].setAccountType("Savings");
    accounts[0].setBalance(100);
    accounts[0].setInterestRate(0.46);
    cout << "----------------------------------------------" << endl;

    accounts[1].setAccountHolderName("Ronnie Coleman");
    accounts[1].setAccountType("Savings");
    accounts[1].setBalance(8);
    accounts[1].setInterestRate(.46);
    cout << "----------------------------------------------" << endl;

    accounts[2].setAccountHolderName("Chris Bumstead");
    accounts[2].setAccountType("checking");  // Showing error message for typo in account type
    accounts[2].setAccountType("Checking");
    accounts[2].setBalance(6);
    accounts[2].setInterestRate(.06);
    cout << "----------------------------------------------" << endl;

    const int NUMBER_OF_DEMONSTRATION_ACCOUNTS = 3;
    int withdrawal_amount;

    for (int i = 0; i < NUMBER_OF_DEMONSTRATION_ACCOUNTS; i++) {
        cout << "This account belongs to " << accounts[i].getAccountHolderName() << "." << endl;
        cout << "The account number is '" << accounts[i].getAccountNumber() << "'." << endl;
        accounts[i].deposit(1000);

        if (i == 2) {
            withdrawal_amount = 2500;
            accounts[i].withdraw(withdrawal_amount); // Showing error message if withdrawing too much from the account
            withdrawal_amount = 250;
            accounts[i].withdraw(withdrawal_amount);
            accounts[i].setAccountType("Savings");
            accounts[i].setInterestRate(.046);
        }
        else {
            withdrawal_amount = 150;
            accounts[i].withdraw(withdrawal_amount);
            accounts[i].setAccountType("Checking");
            accounts[i].setInterestRate(.08);
        }
        cout << "-------------------------------------------------------------------" << endl;
    
    }

    return 0;

}