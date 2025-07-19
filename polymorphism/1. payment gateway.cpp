#include<bits/stdc++.h>
using namespace std;

class Payment {
    public:
        virtual void pay(int amount) = 0;
};

class CreditCard: public Payment {
    private:
    void pay(int amount) override {
        cout << "Paying " << amount << " using credit Card.\n";
    }
};

class UPI: public Payment {
    public:
    void pay(int amount) override {
        cout << "Paying " << amount << " using UPI.\n";
    }
};

void completeTransactions(Payment* method, int amt) {
    method->pay(amt);
}

// void completeT(CreditCard obj, int amt) {
//     obj.pay(amt);
// }
// void completeT(UPI obj, int amt) {
//     obj.pay(amt);
// }

int main() {

    Payment* p1 = new CreditCard();     //? this is call upcasting
    Payment* p2 = new UPI();

    p1->pay(100);
    p2->pay(200);
    // completeTransactions(p1, 100);
    // completeTransactions(p2, 1001);

    // CreditCard c;
    // UPI u;
    // completeT(c, 100);
    // completeT(u, 100);

return 0;
}