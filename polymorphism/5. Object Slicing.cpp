#include<bits/stdc++.h>
using namespace std;

class Employee {
    public:
        string name;
        int id;

        Employee(string n, int i) : name(n), id(i) {}

        virtual void display() {
            cout << "Employee Name: " << name << ", ID: " << id << endl;
        }
};

class Manager : public Employee {
    public:
        int teamSize;

        Manager(string name, int id, int teamSize) : Employee(name, id), teamSize(teamSize) {}

        void display() {
            cout << "Manager Name: " << name << ", ID: " << id
                << ", Team Size: " << teamSize << endl;
        }
};

int main() {

    // Manager m("ravi", 1, 10);

    // Employee e = m;

    // e.display();    // here team size is missing
    // m.display();

    Employee* e1 = new Manager("ravi", 1, 10);
    e1->display();

return 0;
}