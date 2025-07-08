#include<bits/stdc++.h>
using namespace std;

class Parent {
    public:
        void greet() {
            cout << "hello from parents" << endl;
        }
};

class Child: public Parent {
    public:
        void sayHi() {
            cout << "Hi from child" << endl;
        }
};

int main() {

    Child c1;

    c1.greet();
    c1.sayHi();

return 0;
}