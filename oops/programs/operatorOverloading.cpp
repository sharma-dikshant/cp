#include <bits/stdc++.h>
using namespace std;

class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction (int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
        }

        Fraction add (Fraction f) {
            int n_num  = this->numerator * f.denominator + this->denominator * f.numerator;
            int n_deno = this->denominator * f.denominator;

            return Fraction(n_num, n_deno);
        }

        Fraction operator+ (Fraction f) {
            int n_num  = this->numerator * f.denominator + this->denominator * f.numerator;
            int n_deno = this->denominator * f.denominator;

            return Fraction(n_num, n_deno);
        }



        void print () {
            cout<<this->numerator<<"/"<<this->denominator<<endl;
        }
};

int main() {

    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction f3 = f1 + f2;
    f3.print();
    f1.add(f2).print();

    return 0;
}