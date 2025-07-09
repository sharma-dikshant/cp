#include<bits/stdc++.h>
using namespace std;

class Student {
    public:
        int roll_no;
        string name;

        Student() {     // Default Constructor
            cout << "Default Constructor" << endl;
        }

        Student(int roll_no, string name) {     // Parametrized contructor
            this->name = name;
            this->roll_no = roll_no;
            cout << "Parametrized Constructor" << endl;
        }

        // Student(Student& s) {
        //     this->name = s.name;
        //     this->roll_no = s.roll_no;
        //     cout << "Copy Constructor" << endl;
        // }

        ~Student() {
            cout << "Destructor" << endl;
        }

        void show() {
            cout << "name: " << this->name << " roll no: " << this->roll_no << endl;
        }
};

int main() {

    Student s1;
    Student s2(1, "Dikshant");
    Student s3 = s2;

    // s2.name = "Dikshant Sharma";
    s3.roll_no = 1000;

    s1.show(); s2.show(); s3.show();

return 0;
}