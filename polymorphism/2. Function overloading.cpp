#include<bits/stdc++.h>
using namespace std;

class Print {
    public:
        void print(int x) { cout << x << endl; }
        void print(string x) { cout << x << endl; }
        void anotherPrint(string x1, string x2) { print(x1, x2); }
    private:
        void print(string x1, string x2) { cout << x1 << x2 << endl; }

};

int main() {

    Print p;
    p.print(2);
    p.print("hello");
    p.anotherPrint("hello", "world");

return 0;
}