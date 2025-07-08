#include<bits/stdc++.h>
using namespace std;

/**
 * ! Interface enforces a contract : any class inheriting from theri must implement (override) all the listed virtual functions
 */

class Automobile {

    public:
        virtual void drive() = 0;
        virtual void run() = 0;
};

class Bike: public Automobile {
    public:
        int speed;
        int type;

        void drive() override {
            cout << "driving bike";
        }

        void run() override {
            cout << "running on bike";
        }
};

int main() {

    Bike* b = new Bike();


return 0;
}