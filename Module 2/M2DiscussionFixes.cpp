//Max Jankowski
//CIS 310 week 2 discussion

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int numTickets;
    float price = 35.25;
    float totalPrice;

    //asking for the amount of tickets user want to buy

    cout << "How many tickets would you like to purchase?- " << endl;
    cin >> numTickets;
    cout << endl;
    //calculating total ticket price

    totalPrice = numTickets * price;

    // providing total to the second decimal place
    cout << fixed << showpoint<< setprecision(2);
    cout << "Your total is, $ " << totalPrice << endl;

    return 0;

}