#include<bits/stdc++.h>
using namespace std;

class A {
        int secretKey;
    public:
        A() { secretKey = 10; }

        friend void showSecretKey(A obj);
};

void showSecretKey(A obj) {
    cout << obj.secretKey << endl;
}

// void nonfriendFn(A obj) {
//     cout << obj.secretKey << endl; //! this will throw error
// }

int main() {

    A a;

    showSecretKey(a);

return 0;
}