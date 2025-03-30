#include <bits/stdc++.h>
using namespace std;

class Scooty {
    public:
        int topSpeed;
        int milage;
};


class Bike: public Scooty {
    public:
        int gears;
        Bike(int topSpeed, int milage, int gears) {
            this->topSpeed = topSpeed;
            this->milage = milage;
            this->gears = gears;
        }

        void getter() {
            cout<<topSpeed<<endl;
            cout<<milage<<endl;
            cout<<gears<<endl;
        }
};

class Hybrid : public Scooty, Bike {    // multiple inheritence 

};


int main() {

    Bike b1(110, 35, 5);
    b1.getter();

    return 0;
}