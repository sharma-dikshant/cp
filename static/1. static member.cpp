#include<bits/stdc++.h>
using namespace std;

class Student {
    public:
        static int count;
        string name;

        Student(string name) {
            this->name = name;
            count++;
        }
};

int Student::count = 0;

int main() {

    Student s1("Dikshant"), s2("Ravi"), s3("rahul");
    cout << Student::count << endl;

return 0;
}