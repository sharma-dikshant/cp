#include <bits/stdc++.h>
using namespace std;

class A1 {
    public:
        void f1 (int a) { cout<<"f1-A1"; }
};

class A2 {
    public:
        void f1 () { cout<<"f1-A2"; }
};

class B: public A1, public A2 {
    public:
        void f1 (int a) { cout<<"f1-B"; }
};

int main()
{   
    B obj;
    obj.f1(5);
    return 0;
}