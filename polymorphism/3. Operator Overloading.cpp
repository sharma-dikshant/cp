#include<bits/stdc++.h>
using namespace std;

class Complex {
    public:
        int imag, real;
        Complex(int r, int i) : imag(i), real(r) { };

        Complex operator + (const Complex& c) {
            return Complex(real + c.real, imag + c.imag);
        }

        void print() {
            cout << real << " + i" << imag << endl; 
        }

};

class Number {
    public:
        int n;
        Number (int n) : n(n) {};

        Number operator * (Number a) {
            return Number((int)(pow(n, a.n)));
        }
};

int main() {

    // Complex x(1, 2), y(5, 7);
    // Complex z = x + y;

    // x.print(); y.print(); z.print();

    Number x(2), y(5);
    Number z = x * y;
    cout << z.n << endl; 

return 0;
}