#include <bits/stdc++.h>
using namespace std;

class A1
{
public:
    virtual void f1() { cout << "f1-A1"; }
};

class A2
{
public:
    void f1() { cout << "f1-A2"; }
};

class B : public A1, public A2
{
public:
    void f1() { cout << "f1-B"; }
};

int main()
{
    A1 *p;
    p = new B;
    p->f1();

    /*
        Virtual function is a member function in the base class that you expect to override in derived classes.
        Also when you make a function virtual then you are telling the compiler to use dynamic binding for that function.
        One more points is that if f1 function is virtual in the base class then it will be virtual in the derived classes also.

        therefore, if the binding is runtime then B class object is created and pointer p is pointing to that object and hence the f1 of class B will be called.
    */

    return 0;
}