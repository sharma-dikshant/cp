#include <bits/stdc++.h>
using namespace std;

class Dummy {

    int a;

    public:
        void set_a(int x) { a = x; }   // instance member function
        static void show_a() { cout << a << endl; } // static member function
};

int main()
{

    Dummy d1;
    d1.set_a(5);
    d1.show_a();


    /*
        Instance member function can access instance variables and static variables.
        Static member function can access only static variables.
    */

    return 0;
}