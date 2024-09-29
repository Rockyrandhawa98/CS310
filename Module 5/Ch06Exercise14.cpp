#include <iostream>
#include <iomanip>

using namespace std;

// function to find price of consultation
float consulting_price (float& hourly, int& consult_time, string& income) { 

    float additional_time;
    float service_charge_percentage;
    float result;

    if (income == "Yes") {
        service_charge_percentage = 0.4;
        if (consult_time <= 30) {
            result = 0;
            return result;
        }
        else {
            additional_time = consult_time - 30;
            result = (hourly * service_charge_percentage) * (additional_time / 60);
            return result;

        }
    }
    else {
        service_charge_percentage = 0.7;
        if (consult_time <= 20) {
            result = 0;
            return result;
        }
        else {
            additional_time = consult_time - 20;
            result = (hourly * service_charge_percentage) * (additional_time / 60);
            return result;
        }
        }
    }


int main() {

    float hourly_rate;
    int consulting_time;
    string low_income;
    float consultation_price;

    cout << "Enter the hourly rate for consulting: " << endl;
    cin >> hourly_rate;

    cout << "\nEnter the total consulting time in minutes: " << endl;
    cin >> consulting_time;

    cout << "\nDo you qualify as having low income?" << endl;
    cout << "Low income means you earn less than or equal to $25,000 per year." << endl;
    cout << "Enter 'Yes' if you qualify as having low income and 'No' if you do not (this input is case-sensitive): " << endl;
    cin >> low_income;

    // calling function to store in variable
    consultation_price = consulting_price(hourly_rate, consulting_time, low_income);

    cout << fixed << setprecision(2);
    cout << "\nBased on this information, the price of your consultation will be $" << consultation_price << " " << endl;

    system("pause");
    return 0;
}
