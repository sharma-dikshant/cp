#include <bits/stdc++.h>
using namespace std;

// compile time -> function overloading
// to overload a function either the quality or the quantity of parameters should be different

class Test {
    public:
        void sum (int a, int b) {
            cout<<a + b<<endl;
        }

        void sum (int a, int b, int c) {
            cout<<a + b+ c<<endl;
        }

        int sum (int a, int b, int c, int z) {
            cout<<a+ b<<endl;
            return -1;
        }
};

int main()
{

    return 0;
}