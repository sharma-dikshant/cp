#include<bits/stdc++.h>
using namespace std;

class A {

    public:
        virtual void draw() {
            cout << "Class A" << endl;
        }

};

class B: public A {

    public:
        void draw() {
            cout << "Class B" << endl;
        }
};

int main() {

    // B obj;
    A* obj = new B();      //! this will through error as A is an inaccessible base of B
    obj->draw();

    /**
            to understand this 

            let

            class PrivateJet {};
            class Car: private PrivateJet() {};

            here, Car is privately inheriting the PrivateJet. Which does not make sense in real world.
            but it is like Car is using some internal inplementations of PrivateJet.

            but 
            PrivateJet* c = new Car();

            this line says that treat car as PrivateJet. Which should not be done
     */

return 0;
}