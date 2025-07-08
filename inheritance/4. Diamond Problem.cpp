#include<bits/stdc++.h>
using namespace std;

class A {
    public: 
        void greet() { cout << "Hello." << endl; }
};

class B: public A { };
class C: public A { };

class D: public B, public C { };

int main() {

    D obj;
    obj.greet();    //! this will throw compile time error : Ambiguity error

return 0;
}