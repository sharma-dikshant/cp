#include<bits/stdc++.h>
using namespace std;

class A {
    public:
        int* id;
        A(int a) {
            id = new int[a];
        }

        void show() { cout << *id << endl; }
};

/*
    class A {
public:
    int* id;

    A(int a) {
        id = new int[a];
        id[0] = a; // put some value
    }

    // ✅ Deep Copy Constructor
    A(const A& other) {
        id = new int[1];
        *id = *other.id;
        cout << "Deep Copy Constructor Called\n";
    }

    void show() { cout << *id << endl; }

    ~A() {
        delete[] id;
        cout << "Destructor Called\n";
    }

    main() [
        A a1(2);      // id = new int[2]
A a2 = a1;    // deep copy, new memory
a2.id = new int[10]; // this is now fine

a1.show(); a2.show();
    ]
};


*/

int main() {

    A a1(2);
    A a2 = a1;

    a2.id = new int[10];

    a1.show(); a2.show();

return 0;
}