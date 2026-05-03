#include<bits/stdc++.h>
using namespace std;

class  A  {
    public:
        void f1() { cout << "A::f1()" << endl; }
};

class B: public A {
    public:
        void f1(int x) { cout << "B::f1()" << endl; }
};

int main() {

    B obj;
    obj.f1();


    /*
    function hiding: 
    When a derived class has a member function with the same name as a member function in the base class,
    the derived class function hides the base class function. This means that the base class function is not accessible through the derived class object.

    function overriding:
    When a derived class has a member function with the same name and signature as a member function in the base class,
    the derived class function overrides the base class function. This means that when the derived class object calls the function,
    the derived class function is executed instead of the base class function.
    In this case, the base class function is not hidden, and it can still be accessed using a base class pointer or reference.


    function overloading: 
    When a class has multiple member functions with the same name but different signatures (different parameter types or number of parameters), but all the candidate function should be in the same scope.
    
    */

return 0;
}