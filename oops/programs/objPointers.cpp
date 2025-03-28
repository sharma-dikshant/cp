#include <bits/stdc++.h>
using namespace std;

class Cricketer {
    public:
        string name;
        int age;
        int runs;
        float avg;

        Cricketer() { }
        Cricketer(string name, int age, int runs, float avg) {
            this->name = name;
            this->age = age;
            this->runs = runs;
            this->avg = avg;
        }

        void print() {
            cout<<"**"<<this->name<<"**"<<endl;
            cout<<"age: "<<this->age<<endl;
            cout<<"total runs: "<<this->runs<<endl;
            cout<<"average: "<<this->avg<<endl;
        }
};

void change(Cricketer* p) {
    // (*p).avg = 77.5;
    //this can be done using arrow operator
    p->avg = 77.5;
}

int main() {

    Cricketer c1("Virat Kohli", 36, 25000, 57);
    Cricketer c2("Rohit Sharma", 42, 15000, 48);

    // c1.print();
    // c2.print();

    /*
    int x = 4;
    cout<<&x<<endl;     // prints the address of x
    int* ptr = &x;      // we store the address of x in pointer ptr
                        // type of ptr is int* bec. it store the pointer of an integer
                        // therefore it can be said that int* is a data type
    cout<<ptr<<endl;

    *ptr = 100; 
    */

    // Performing same operations on c1 object using pointer
    Cricketer* p1 = &c1;
    cout<<(*p1).name<<endl;
    (*p1).name = "Kane";
    change(&c1);
    c1.print();

    return 0;
}