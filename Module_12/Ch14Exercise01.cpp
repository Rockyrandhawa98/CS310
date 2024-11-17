#include <iostream>
#include <exception>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::exception;
using std::string;
using std::set;


// source for Exception Handling: https://www.youtube.com/watch?v=5nCXSDv6e4I
class negativeNumber : public exception {
    public:
        const char * what() const noexcept {
        return "\nError: Cannot enter a negative number";
    }

};


class nonNumber : public exception {
    public:
    const char * what() const noexcept {
        return "\nError: Input must be a number";
    }

};


double toCentimeter(double feet, double inches);
double validateNumber(string number);


int main() {

    double feet = validateNumber("feet");
    double inches = validateNumber("inches");

    double centimeters = toCentimeter(feet, inches);

    cout << feet << " feet and " << inches << " inches converts into " << centimeters << " centimeters." << endl;

    return 0;
}


double toCentimeter(double feet, double inches) {
    return ((feet * 12) + inches) * 2.54;
}


double validateNumber(string number) {
    string num;
    while (true) {
        try {
            cout << "Enter the number of " << number << ": " << endl;
            cin >> num;

            set<char> validInputs = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '-'};

            for (int i = 0; i < num.size(); i++) {
                if (!(validInputs.count(num[i]) == 1)) {
                    throw nonNumber();
                }
            }

            // source for conversion: https://stackoverflow.com/questions/4754011/how-to-convert-a-stdstring-to-double
            double val = stod(num);
            
            if (val < 0) {
                throw negativeNumber();
            }

            return val;
        }
        catch (negativeNumber &e) {
            cout << e.what() << endl;
        }
        catch (nonNumber &e) {
            cout << e.what() << endl;
        }
    }
}
