#include<bits/stdc++.h>
using namespace std;

class User {
    private: 
        string password;
    public:
        string name;
        int age;
    protected: 
        string department;
};

class Employee: public User {  };

int main() {

    Employee e1;
    e1.password;
    e1.name;
    e1.age;
    e1.department;

return 0;
}