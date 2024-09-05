#include <locale>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float netBalance, payment, d1, d2, interestPerMonth;

    cout << "What is the balance shown in the bill? ";
    cin >> netBalance;

    cout << "What is the current payment made? ";
    cin >> payment;

    cout << "How many days are in the billing cycle? ";
    cin >> d1;

    cout << "How many days before the billing cycle was the payment made? ";
    cin >> d2;

    cout << "What is the interest rate per month? ";
    cin >> interestPerMonth;

    float interest = interestPerMonth * ((netBalance * d1 - payment * d2) / d1);

    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    cout << interest;
    
    return 0;
}
