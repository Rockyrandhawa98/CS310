#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Some generic animal sound!" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Woof!" << endl;
    }
    void fetch() {
        cout << "Fetching the ball!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Meow!" << endl;
    }
    void climbTree() {
        cout << "Climbing the tree!" << endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    // Dereferencing the pointer and assigning it to a new object of type Dog, then using the fetch() method
    myDog->speak();  
    Dog* pMyDog = dynamic_cast<Dog*>(myDog);
    Dog dog = *pMyDog;
    dog.fetch();

    // Directly accessing the climbTree() method by using a pointer
    myCat->speak();
    Cat* pMyCat = dynamic_cast<Cat*>(myCat);
    pMyCat->climbTree();

    delete myDog;
    delete myCat;

    return 0;
}