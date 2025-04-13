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
    B obj;
    obj.f1();
    return 0;
}

/*
here, the class B has its own function f1 which will be called when we call obj.f1().
so wherever there is the called function in the respective class then it will not go to the base class.
if the class B does not have its own function f1 then it will go to the base class A1 or A2.

*/