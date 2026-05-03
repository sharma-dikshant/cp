#include <bits/stdc++.h>
using namespace std;

int f1(int);
void f1(int);

int main()
{   
   int y = f1(4);

    /*
        Condition for function overloading:
        1. Function name should be same.
        2. Function signature should be different.


        Function signature: fn_name + parameter type + number of parameters + order of parameters.
        Note: return type is not part of function signature.

        Function prototype: fn_name + parameter type + number of parameters + order of parameters + return type.
        Note: return type is part of function prototype.
    */

    /*
        therefore, here the function signature of both function is same. 
        therefore, it cause ambiguity.
        So the compiler will give an error that which f1 to call.
    */

    return 0;
}

int f1(int a)
{
    cout << "f1(int) called" << endl;
    return 0;
}
void f1(int a)
{
    cout << "f1(void) called" << endl;
}