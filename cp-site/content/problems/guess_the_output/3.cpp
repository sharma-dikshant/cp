#include <bits/stdc++.h>
using namespace std;

class A1 {
    public:
        void f1 () { cout<<"f1-A1"; }
};

class A2 {
    public:
        void f1 (int a) { cout<<"f1-A2"; }
};

class B: public A1, public A2 {
    public:
};

int main()
{   
    B obj;
    obj.f1();
    obj.f1(3);
    return 0;
}


/*
    Now, first of all this is not the case of function overloading, i.e. the function f1 is not
    overloaded
    Because to overload a function, all the overloaded versions of that function must be in the same class.
    And if it is the case of function overloading then the compiler will not give an error and call the respective overloaded version.

    But here both the functions f1 are in different classes. So the compiler will first look at the class B, if there is no f1 then it will decide to look the base classes for f1 function defination. But here the compiler will find that there are two f1 functions in the base classes A1 and A2. So it will give an error that which f1 to call.

    To resolve this ambiguity we can use scope resolution operator to specify which f1 we want to call.
*/
