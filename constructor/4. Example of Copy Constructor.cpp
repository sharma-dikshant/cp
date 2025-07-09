#include<bits/stdc++.h>
using namespace std;

class Test {
    public:
        int* data;

        Test(int val) {
            data = new int(val);
            cout << "Constructor is Called! " << *data << endl;
        } 

        void show() { cout << "value: " << *data << endl;}

        ~Test() {
            delete data;
            cout << "Destructor is called!" << endl;
        }
};

void insideFn(Test t) {
   cout << "inside func" << endl;
   t.show();
}

/**
 * 💡 Takeaway Interview Trick:
        - Jab object pass-by-value hota hai (function me), copy constructor call hota hai
        - Agar pointer member hai aur copy constructor shallow hai ⇒ double delete / crash
        - Always use deep copy agar pointer members ho
 */

int main() {

    Test t(101);
    insideFn(t);

    cout << "Back to main" << endl;
    t.show();

return 0;
}