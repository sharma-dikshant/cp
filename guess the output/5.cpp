#include <bits/stdc++.h>
using namespace std;

class A1 {
    public:
        void f1 () { cout<<"f1-A1"; }
};

class A2 {
    public:
        void f1 () { cout<<"f1-A2"; }
};

class B: public A1, public A2 {
    public:
        void f1 () { cout<<"f1-B"; }
};

int main()
{   
    A1 *p;
    p = new B;
    p->f1();


    /*
        we know that compiler done early binding of the function calls. 
        So when the comipler come to p->f1() then it will check how call the f1. 
        here it see that a pointer p is calling. 
        Although the pointer p is pointing to the object of class B but during the compile time no memory is allocated for the object of class B.
        So the compiler will check the type of the pointer p, which is A1.
        So it will call the f1 of class A1.
        So the output will be f1-A1.
    */


    return 0;
}