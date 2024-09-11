#include <iostream>
using namespace std;

int main () {
    int books_sold;
    float price_per_novel;
    float choice2_rate = .125;
    float choice3_rate_first_4000 = .10;
    float choice3_rate = .14;

    cout << "Enter the net price per novel: ";
    cin >> price_per_novel;
    cout << "How many books do you think will be sold? ";
    cin >> books_sold;

    
    float choice1 = 25000.00;
    float choice2 = choice2_rate * price_per_novel * books_sold;

    int remaining_books = 0;
    if (books_sold > 4000) {
        remaining_books = books_sold - 4000;
        books_sold = 4000;
    }

    float choice3 = (choice3_rate_first_4000 * price_per_novel * books_sold) + (choice3_rate * price_per_novel * remaining_books);

    cout << " " << endl;
    cout << "Your royalty options are as listed: " << endl;
    cout << "1) Being paid $5,000 when delivering the final manuscript and an additional $20,000 when publishing the novel" << endl;;
    cout << "2) Being paid 12.5 percent in royalties for each copy sold" << endl;
    cout << "3) Being paid 10 percent per copy for the first 4,000 books sold, along with being paid 14 percent for each copy past 4,000 units" << endl;
    cout << " " << endl;

    cout << "Option 1 would result in net royalties of $" << choice1 << "." << endl;
    cout << "Option 2 would result in net royalties of $" << choice2 << "." << endl;
    cout << "Option 3 would result in net royalties of $" << choice3 << "." << endl;
    cout << " " << endl;

    cout << "Based on these results, your best choice is " ;

    if (choice1 > choice2 && choice1 > choice3) {
        cout << "option 1, where you will make $" << choice1 << "." << endl;
    }
    else if (choice2 > choice1 && choice2 > choice3) {
        cout << "option 2, where you will make $" << choice2 << "." << endl;
    }
    else if (choice3 > choice2 && choice3 > choice1) {
        cout << "option 3, where you will make $" << choice3 << "." << endl;
    }
    else if (choice1 == choice2) {
        cout << "either option 1 or option 2, since they both result in net royalties of $" << choice1 << "." << endl;
    }
    else if (choice1 == choice3) {
        cout << "either option 1 or option 3, since they both result in net royalties of $" << choice1 << "." << endl;
    }
    else if (choice2 == choice3) {
        cout << "either option 2 or option 3, since they both result in net royalties of $" << choice2 << "." << endl;
    }
    else {
        cout << "whichever one you prefer, since all options result in the same net royalties of $" << choice2 << "." << endl;
    }

    cout << " " << endl;
    system("pause"); // source: https://stackoverflow.com/questions/2529617/how-to-stop-c-console-application-from-exiting-immediately

    return 0;

}
