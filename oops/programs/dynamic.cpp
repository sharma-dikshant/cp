#include <bits/stdc++.h>
using namespace std;

class Person {
    public:
        string name;
        Person() {}
        Person(string name) {
            this->name = name;
        }
        ~Person() {
            cout<<this->name<<" is deleted!";
        }

};
void justify () {
    Person c1("Virat Kohli");
    Person* c2 = new Person("Rohit Sharma");
}

int main()
{   
    justify();
    return 0;
}