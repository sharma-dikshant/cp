#include <bits/stdc++.h>
using namespace std;

class Dummy {
    public:
        int a;          //instance variable
        static int k;   //static variable
};

// defination of static variable
int Dummy::k = 0; // static variable must be initialized outside the class
// and Dummy::x is called membership label

int main() {

    Dummy d1, d2;
    d1.a = 5;
    d1.k = 10;

    cout<<d2.a<<endl; 
    cout<<d2.k<<endl; 

    /*
        Although the k variable is static, But still we need to define 
        it outside the class.
        If not defined outside the class, then it will give an error as in this case
    */
    return 0;
}