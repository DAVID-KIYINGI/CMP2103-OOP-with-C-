#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() const {
        cout << "Animal makes a sound" << endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    Animal* animalPtr = nullptr;

    cout << "Using the same base-class pointer and function call:" << endl;

    animalPtr = &dog;
    animalPtr->sound();

    animalPtr = &cat;
    animalPtr->sound();

    return 0;
}
