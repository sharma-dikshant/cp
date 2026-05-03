#include <bits/stdc++.h>
using namespace std;

int f1(double);
void f1(float);

int main()
{   
   char x = 'A';
   f1(x);

    return 0;
}

int f1(double a)
{
    cout << "f1(int) called" << endl;
    return 0;
}
void f1(float a)
{
    cout << "f1(void) called" << endl;
}

/*
    here, both first and second rules are not applicable.
    because there is no exact match and no promotion possible.
    therefore the compiler will try to convert the argument type to the function parameter type.
    so the char is converted to double and float also, which cause ambiguity.
*/

