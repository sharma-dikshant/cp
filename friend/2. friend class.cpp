#include<bits/stdc++.h>
using namespace std;

class A {
    private:
    int data;
    
    public:
    A() { data = 100; }
    
    friend class B;     //? this function can be written anywhere in the class
};

class B {
    public:
        void show(A obj) {
            cout << obj.data << endl;
        }
};

int main() {

    A a;
    B b;

    b.show(a);

return 0;
}