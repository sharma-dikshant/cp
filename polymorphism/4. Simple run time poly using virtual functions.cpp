#include<bits/stdc++.h>
using namespace std;

class Animal {
    public:
        virtual void speak() = 0;
};

class Dog: public Animal {
    public:
        virtual void speak() = 0; //? here override keyword is optional
};

class Puppy: public Dog {
    public: 
        void speak() { cout << "puppy" << endl; }
};

int main() {

    Animal* a = new Puppy();
    a->speak();
    // Dog d;
    // d.speak();
return 0;
}