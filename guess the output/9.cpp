#include <bits/stdc++.h>
using namespace std;

int f1(int);
void f1(float);

int main()
{   
   char x = 'A';
   f1(x);

    return 0;
}

int f1(int a)
{
    cout << "f1(int) called" << endl;
    return 0;
}
void f1(float a)
{
    cout << "f1(void) called" << endl;
}


/*
    Whenever there is a case of function overloading, to bind the fuction call compiler do the following steps:
    1> Collect all the overloaded functions in the same scope, which are known as the candidate functions.
    2> Now compiler need to decide which function is appropriate to call from all the candidate functions.

    3> for this compiler follows 3 rules
    i) Exact match: if there is a function which is exactly matching the function call then that function will be called.
    ii) Promotion: if there is no exact match then the compiler will try to promote the argument type to the function parameter type. 
    char -> int  float -> double


    iii) Type conversion: if there is no exact match and no promotion possible then the compiler will try to convert the argument type to the function parameter type. For example, if the function parameter is float and the argument is int then the compiler will convert the int to float and call that function.
*/

/*
    primitive data types:
    char, int, float, double, bool (all the built in data types are primitive data types)
    non primitive data types:
    array, structure, union, class, string (all the user defined data types are non primitive data types)
    Note: string is not a primitive data type, it is a non primitive data type. But in C++ it is treated as a primitive data type because it is a built in data type in C++.

    
*/