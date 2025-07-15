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

int main() {

    Complex x(1, 2), y(5, 7);
    Complex z = x + y;

    x.print(); y.print(); z.print();

return 0;
}