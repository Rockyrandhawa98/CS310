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


double validateNumber(string number);
double toCentimeter(double feet, double inches);
void print(double feet, double inches, double centimeters);


int main() {
    double feet = validateNumber("feet");
    double inches = validateNumber("inches");
    double centimeters = toCentimeter(feet, inches);
    print(feet, inches, centimeters);

    return 0;
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
            
            // random edge case I found where -0 wouldn't count as a negative number
            if (val < 0 || val == -0) {
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

double toCentimeter(double feet, double inches) {
    return ((feet * 12) + inches) * 2.54;
}

void print(double feet, double inches, double centimeters) {
    cout << feet << " feet and " << inches << " inches converts into " << centimeters << " centimeters." << endl;
}
