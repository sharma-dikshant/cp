#include <bits/stdc++.h>
using namespace std;

int f1(int);
void f1(float);

int main()
{   
   f1(4);
   f1(4.4f);

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