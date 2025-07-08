#include<bits/stdc++.h>
using namespace std;

class Car {
    public:
        string brand;
        int speed;

        void drive() {
            cout << "Driving " << brand << " at " << speed << "kmph" << endl;
        }
};

int main() {

    Car c1;
    c1.brand = "audi", c1.speed = 100;
    c1.drive();

return 0;
}