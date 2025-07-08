#include<bits/stdc++.h>
using namespace std;

class Shape {
    public:
        virtual void draw() = 0;
        void info() {
            cout << "This is a shape.\n";
        }
};

class Rectangle: public Shape {
    public:
        void draw() override {
            cout << "This is Rectangle. \n";
        }
};

int main() {

    Rectangle r;
    r.draw();
    r.info();

return 0;
}