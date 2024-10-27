#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

class BankAccount {
    private:
        int accountNumber;
        double balance;
    
    public:
        // set methods
        void setAccountNumber(int accountNumber) {
            this->accountNumber = accountNumber;
        }
        void setBalance(double balance) {
            this->balance = balance;
        }

        // get methods
        int getAccountNumber() {
            return this->accountNumber;
        }
        double getBalance() {
            return this->balance;
        }

        // Class methods
        void deposit(double depositAmount) {
            this->balance += depositAmount;
        }
        void withdraw(double withdrawAmount) {
            if (this->balance < withdrawAmount) {
                cout << "Your account does not have enough balance to withdraw $" << withdrawAmount << "." << endl;
            }
            else {
                this->balance -= withdrawAmount;
            }
        }
        void print() {
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Account Number: " << this->accountNumber << endl;
            cout << fixed << setprecision(2);
            cout << "Balance: $" << this->balance << endl;
        }

    // Constructors
    BankAccount(){}
    BankAccount(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

};

class CheckingAccount : public BankAccount {
    private:
        double interestRate; // stored as decimal
        double minimumBalance;
        double serviceCharge;

    public:
        // set methods
        void setInterestRate(double interestRate) {
            this->interestRate = interestRate;
        }
        void setMinimumBalance(double minimumBalance) {
            this->minimumBalance = minimumBalance;
        }
        void setServiceCharge(double serviceCharge) {
            this->serviceCharge = serviceCharge;
        }

        // get methods
        double getInterestRate() {
            return this->interestRate;
        }
        double getMinimumBalance() {
            return this->minimumBalance;
        }
        double getServiceCharge() {
            return this->serviceCharge;
        }
        
        // Class methods
        void postInterestRate() {
            double currentBalance = this->getBalance();
            double addedInterest = (currentBalance * this->interestRate);
            double newBalance = currentBalance + addedInterest;
            this->setBalance(newBalance);
        }
        bool verifyAboveMinimumBalance() {
            if (this->getBalance() >= this->minimumBalance) 
                return true;
            else 
                return false;
        }
        void writeCheck(double checkValue) {
            double currentBalance = this->getBalance();
            if (currentBalance >= checkValue) {
                currentBalance -= checkValue;
                this->setBalance(currentBalance);
            }
            else {
                cout << "Not enough funds to write a check of $" << checkValue << "." << endl;
            }
        }
        void withdraw(double withdrawAmount) {
            double currentBalance = this->getBalance();
            if (currentBalance < withdrawAmount) {
                cout << "Your account does not have enough balance to withdraw $" << withdrawAmount << "." << endl;
            }
            else {
                currentBalance -= withdrawAmount;
                this->setBalance(currentBalance);
            }
        }
        void print() {
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Account Number: " << this->getAccountNumber() << endl;
            cout << fixed << setprecision(2);
            cout << "Balance: $" << this->getBalance() << endl;
            cout << fixed << setprecision(4);
            cout << "Interest Rate: " << this->interestRate << "%" << endl;
            cout << fixed << setprecision(2);
            cout << "Minimum Required Balance: $" << this->minimumBalance << endl;
            cout << "Service Charge: $" << this->serviceCharge << endl;
        }

        // Constructors
        using BankAccount::BankAccount;
        CheckingAccount(int accountNumber, double balance, double interestRate, double minimumBalance, double serviceCharge) {
            this->setAccountNumber(accountNumber);
            this->setBalance(balance);
            this->setInterestRate(interestRate);
            this->minimumBalance = minimumBalance;
            this->serviceCharge = serviceCharge;
        }

};

class SavingsAccount : public BankAccount {
    private:
        double interestRate;
    public:
        // set methods
        void setInterestRate(double interestRate) {
            this->interestRate = interestRate;
        }

        // get methods
        double getInterestRate() {
            return this->interestRate;
        }

        // Class methods
        void postInterestRate() {
            double currentBalance = this->getBalance();
            double addedInterest = (currentBalance * this->interestRate);
            double newBalance = currentBalance + addedInterest;
            this->setBalance(newBalance);
        }
        void withdraw(double withdrawAmount) { 
            double currentBalance = this->getBalance();
            if (currentBalance < withdrawAmount) {
                cout << "Your account does not have enough balance to withdraw $" << withdrawAmount << "." << endl;
            }
            else {
                currentBalance -= withdrawAmount;
                this->setBalance(currentBalance);
            }
        }
        void print() {
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Account Number: " << this->getAccountNumber() << endl;
            cout << fixed << setprecision(2);
            cout << "Balance: $" << this->getBalance() << endl;
            cout << fixed << setprecision(4);
            cout << "Interest Rate: " << this->interestRate << "%" << endl;
        }

        // Constructors
        using BankAccount::BankAccount;
        SavingsAccount(int accountNumber, double balance, double interestRate) {
            this->setAccountNumber(accountNumber);
            this->setBalance(balance);
            this->interestRate = interestRate;
        }
        
};

// program to demonstrate class methods
int main () {

    CheckingAccount checking(1, 100, .0007, 50, 10);
    SavingsAccount savings(2, 1500, .0045);

    double transferAmount = 250;

    // outputting starting values for both accounts
    checking.print();
    savings.print();
    cout << "-----------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);

    // fails withdrawal
    checking.writeCheck(transferAmount);
    cout << " " << endl;

    // reassign new amount to transfer, withdrawing from checking and depositing into savings
    transferAmount = 70;
    checking.writeCheck(transferAmount);
    cout << "$" << transferAmount << " has been successfully withdrawn from your account." << endl;

    // checking to see if current balance is below the minimum required balance
    if (!checking.verifyAboveMinimumBalance()) {
        double newAmount = checking.getBalance() - checking.getServiceCharge();
        checking.setBalance(newAmount); 
        cout << "A Service Charge of $" << checking.getServiceCharge() << " was applied to your checking account.\n" << endl;
    }

    cout << "Your checking account now has $" << checking.getBalance() << endl;
    savings.deposit(transferAmount);
    cout << "Your savings account now has $" << savings.getBalance() << "\n" << endl;

    // accrued interest is added to balance
    checking.postInterestRate();
    savings.postInterestRate();

    // withdrawing $1000 from the savings account
    savings.withdraw(1000);

    // showing account information after these transactions
    checking.print();
    savings.print();
    cout << "-----------------------------------------------------------------" << endl;   

    system("pause");
     
    return 0;
}
