#include<bits/stdc++.h>
using namespace std;

class A {
    public: 
        void greet() { cout << "Hello." << endl; }
};

class B: virtual public A { };
class C: virtual public A {
    public:
        void c_greet() {
            cout << "this is greet from c function" << endl;
        }
 };


class D: public B, public C { };

int main() {

    D obj;
    obj.greet();   
    obj.c_greet();

return 0;
}