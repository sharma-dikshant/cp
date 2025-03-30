#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        
        Student() {
            name = "null";
            collage = "SKIT";
            age  = 0;
        }
        Student(string name, int age) {
            this->age  = age;
            this->name = name;
            this->collage = "SKIT";
        }
        
        void getter() {
            cout<<"name: "<<name<<endl;
            cout<<"age: "<<age<<endl;
            cout<<"collage: "<<collage<<endl;
            
        }
        private:
        string collage;
        int age;
};

int main() {

    Student s1("DIkshant", 21);
    Student s2("DIkshant", 22);
    //TODO
    s1 = s2;        //! this works why
    
    s1.getter();
    s2.getter();

    return 0;
}