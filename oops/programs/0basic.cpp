#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        int roll_no;
        float gpa;

        Student() {    // default constructor

        }

        // Student(string n, int r, float g) {  // parametrized constructor
        //     name = n;
        //     roll_no = r;
        //     gpa = g;
        // }

        Student(string name, int roll_no, float gpa) {
            this->name = name;
            this->gpa = gpa;
            this->roll_no = roll_no;
        }

        void print() {
            cout<<"*******"<<endl;
            cout<<"name :"<<this->name<<endl;
            cout<<"roll_no :"<<this->roll_no<<endl;
            cout<<"gpa :"<<this->gpa<<endl;
            cout<<"*******"<<endl;
        }
};

void printStudentDetails(Student s) {
    //this function is pass by value
    // it can be pass by ref using &
    cout<<"*******"<<endl;
    cout<<"name :"<<s.name<<endl;
    cout<<"roll_no :"<<s.roll_no<<endl;
    cout<<"gpa :"<<s.gpa<<endl;
    cout<<"*******"<<endl;
}

int main() {
    Student s1("Dikshant", 76, 8.88);
    // s1.name = "Dikshant";
    // s1.gpa = 8.88;
    // s1.roll_no = 76;

    Student s2 = s1;    // this will create deep copy
    Student s3(s1);     // this will also deep copy //copy constructor can be execute by def constructor
    s2.print();
    
    printStudentDetails(s1);
    printStudentDetails(s2);
    printStudentDetails(s3);
    return 0;
}