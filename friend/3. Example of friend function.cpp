#include<bits/stdc++.h>
using namespace std;

class BankAccount {
    private:
        int amount;
        string name;
    public: 
        BankAccount(string name, int amount) {
            this->name   = name;
            this->amount = amount;
        }

    friend void auditAccount(BankAccount obj);

};

void auditAccount(BankAccount obj) {
    cout << "Audit Report: " << endl;
    cout << "Account holder: " << obj.name << endl;
    cout << "Account Balance: " << obj.amount << endl;
}

int main() {

    BankAccount bk1("Dikshant Sharma", 15000);
    auditAccount(bk1);

return 0;
}