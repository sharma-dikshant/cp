#include<bits/stdc++.h>
using namespace std;

class User {
    private:
        string email;
        static bool isValidEmail(const string& email) {
            return false;    // lets say email is valid
        }
    public:
        User(string email) {
            if (isValidEmail(email)) {
                this->email = email;
                cout << "registered!" << endl;
            } else {
                cout <<"registration failed" << endl;
            }
        }
};

int main() {

    User u("dikshant");

return 0;
}