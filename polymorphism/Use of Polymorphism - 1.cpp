#include<bits/stdc++.h>
using namespace std;

class Employee {
    public:
        virtual void work() = 0;
};

class Manager: public Employee {
    public:
        void work() override { cout << "Manager works!" << endl; }
};

class Intern: public Employee {
    public:
        void work() override { cout << "Intern works!" << endl; }
};

class Engineer: public Employee {
    public:
        void work() override { cout << "Engineer works!" << endl; }
};

void assignWork(Manager m) {
    m.work();
}

int main() {


    Manager m;
    Intern i;
    Engineer e;

    assignWork(m);  // Manager works!
    assignWork(e);  //! Error! because on Manager class object can pass

return 0;
}