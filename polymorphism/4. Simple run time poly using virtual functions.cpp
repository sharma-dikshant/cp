#include<bits/stdc++.h>
using namespace std;

class Animal {
    public:
        virtual void speak() { cout << "this is animal sound" << endl; }
};

class Dog: public Animal {
    public:
        void speak() override { cout << "Barks" << endl; }  //? here override keyword is optional
};

int main() {

    Animal* a = new Dog();
    a->speak();
return 0;
}