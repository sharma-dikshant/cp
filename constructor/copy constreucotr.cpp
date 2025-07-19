#include<bits/stdc++.h>
using namespace std;

class A {
    public:
        int* x;
    
        A() {
            x = new int;
        }

};

int main() {

    A a;
    *a.x = 144;

    A b = a;

    *b.x = 100;

    cout << *a.x << endl;
    cout << *b.x << endl;

return 0;
}