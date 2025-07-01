/*
Problem Statement: Power (a^b)

Given two integers `a` and `b`, calculate the value of `a` raised to the power `b` (a^b). 
The result should be computed efficiently using recursion or iterative methods.

Input:
- Two integers `a` and `b` where:
    - `a` is the base (can be positive, negative, or zero).
    - `b` is the exponent (can be positive, negative, or zero).

Output:
- An integer or floating-point number representing the result of `a^b`.

Constraints:
- -10^9 <= a <= 10^9
- -10^9 <= b <= 10^9
- Handle edge cases such as `a = 0`, `b = 0`, and negative exponents.

Example:
1. Input: a = 2, b = 3
     Output: 8

2. Input: a = 5, b = -2
     Output: 0.04

3. Input: a = 0, b = 0
     Output: Undefined (or handle as 1 based on convention)

4. Input: a = 0, b = 5
     Output: 0

Write a function to solve the problem efficiently.
*/


#include<bits/stdc++.h>
using namespace std;

double power(double a, int b) {
    double res = 1;

    while (b) {
        if (b & 1) {
            res *= a;
        }

        a *= a;
        b >>= 1;
    }

    return res;
}

int main() {

    int a,b;
    cin>>a>>b;

    if (b == 0) {
        cout << 1 << endl;
        return 0;
    }

    if (b < 0) {
        cout << power(1.0/a, b * -1) << endl;
    } else {
        cout << power(a, b) << endl;
    }

return 0;
}