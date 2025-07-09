#include <iostream>
using namespace std;

class BankAccount {
    private:
        string name;
        int balance;

    public:
        BankAccount(string n, int b) {
            name = n;
            balance = b;
        }

        void showBalance() {
            cout << "Account Holder: " << name << ", Balance: ₹" << balance << endl;
        }

        // Declare ATM as friend
        friend class ATM;
};

class ATM {
    public:
        void withdraw(BankAccount& acc, int amount) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                cout << "Withdrawal of ₹" << amount << " successful.\n";
            } else {
                cout << "Insufficient balance.\n";
            }
        }

        void checkBalance(const BankAccount& acc) {
            cout << "ATM Checking Balance: ₹" << acc.balance << endl;
        }
};

int main() {
    BankAccount user("Dikshant", 10000);
    ATM atm;

    atm.checkBalance(user);      // Accessing private member
    atm.withdraw(user, 3000);    // Modifying private member
    atm.checkBalance(user);      // Updated balance

    user.showBalance();          // Also accessible via member function

    return 0;
}
