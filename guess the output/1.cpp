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
};

int main()
{   
    B obj;
    obj.f1();
    return 0;
}

/*
    here we have two classes A1 and A2 both having a function f1.
    class B is inheriting both A1 and A2.
    when we call obj.f1() it will give an error because the compiler does not know which f1 to call.
    to resolve this ambiguity we can use scope resolution operator to specify which f1 we want to call.
    for example:
    obj.A1::f1(); // this will call f1 from A1
*/