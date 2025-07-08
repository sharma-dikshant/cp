#include<bits/stdc++.h>
using namespace std;

class Payment {
    public:
        virtual void pay(int amount) = 0;
};

class CreditCard: public Payment {
    void pay(int amount) override {
        cout << "Paying " << amount << " using credit Card.\n";
    }
};

class UPI: public Payment {
    void pay(int amount) override {
        cout << "Paying " << amount << " using UPI.\n";
    }
};

void completeTransactions(Payment* method, int amt) {
    method->pay(amt);
}

int main() {

    Payment* p1 = new CreditCard();
    Payment* p2 = new UPI();

    completeTransactions(p1, 100);
    completeTransactions(p2, 1001);

return 0;
}