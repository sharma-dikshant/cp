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

void assignWork(Employee* e) {
    e->work();
}

int main() {


    Employee* m = new Manager();
    Employee* e = new Engineer();
    Employee* i = new Intern();

    assignWork(m);
    assignWork(e);
    assignWork(i);

    /**
     * One more use case
     */

    vector<Employee*> record;

    record.push_back(m);
    record.push_back(e);
    record.push_back(i);


return 0;
}