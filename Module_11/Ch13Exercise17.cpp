// Documentation on std::uniform_real_distribution: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution

#include <iostream>
#include <random>

using std::random_device;
using std::mt19937_64;
using std::uniform_real_distribution;
using std::cout;
using std::endl;

int main() {
    random_device device;
    mt19937_64 engine(device());
    uniform_real_distribution distribution(10.0, 100.0001);

    for (int i = 1; i <= 25; i++) {
        cout << "Number " << i << ": " << distribution(engine) << endl;
    }

    return 0;
}
