#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    char* name;

    // Constructor
    Student(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Default Copy Constructor (shallow copy)
    // Compiler-generated

    void show() {
        cout << "Name: " << name << endl;
    }

    ~Student() {
        delete[] name;
        cout << "Destructor called\n";
    }
};

 
int main() {
    Student s1("Dikshant");
    Student s2 = s1; // ⚠️ shallow copy: s1.name and s2.name point to same memory

    s2.name[0] = 'R';  // change s2 -> affects s1 too!

    s1.show(); // ❌ output: Rikshant
    s2.show(); // ❌ output: Rikshant

    return 0;
}
