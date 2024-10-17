#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Temperature {
    private:
        int temperature;

    // get and set methods for each instance of the Temperature class
    public:
        int getTemperature() {
            return temperature;
        }

        int setTemperature(int newTemperature) {
            this->temperature = newTemperature;
        }
    
    // Overloading constructors - first is 0 parameters, second is 1 parameter
    Temperature(){}
    Temperature(int newTemperature) {
        this->temperature = newTemperature;
    }
};


class Weather {
    private:
        string weather;
    
    // get and set methods for each instance of the Weather class
    public:
        string getWeather() {
            return weather;
        }

        void setWeather(string newWeather) {
            this->weather = newWeather;
        }
    
    // Overloading constructors - first is 0 parameters, second is 1 parameter
    Weather{}
    Weather(string newWeather) {
        this->weather = newWeather;
    }
};


int main() {
    Temperature temp;
    Weather weather;

    int todaysTemperature;
    string todaysWeather;

    cout << "What's the temperature today?" << endl;
    cin >> todaysTemperature;

    cout << "What's the weather like?" << endl;
    cin >> todaysWeather;

    temp.setTemperature(todaysTemperature);
    weather.setWeather(todaysWeather);

    cout << "The temperature today is " << temp.getTemperature() << " degrees and it is " \
    << weather.getWeather().append(".") << endl;
    
    return 0;
}

