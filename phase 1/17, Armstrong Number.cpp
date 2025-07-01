/*
Problem Description: Armstrong Number

An Armstrong number (also known as a narcissistic number, or pluperfect digital invariant (PPDI)) is a number that is equal to the sum of its own digits raised to the power of the number of digits.

For example:
- 153 is an Armstrong number because 1^3 + 5^3 + 3^3 = 153.
- 9474 is an Armstrong number because 9^4 + 4^4 + 7^4 + 4^4 = 9474.
- 123 is not an Armstrong number because 1^3 + 2^3 + 3^3 ≠ 123.

Your task is to write a program that checks whether a given number is an Armstrong number or not.

Input:
- A single integer `n` (1 <= n <= 10^6).

Output:
- Print "YES" if the number is an Armstrong number, otherwise print "NO".

Constraints:
- The input number will always be a positive integer.
- The program should handle numbers up to 6 digits efficiently.

Example:
Input: 153
Output: YES

Input: 123
Output: NO
*/


#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
    int t1 = n;
    int t2 = 0;

    while (t1)
    {   
        int t = t1 % 10;
        t2 += t * t * t;
        t1 /= 10;
    }

    return t2 == n;
}

int main() {

    int n;
    cin>>n;

    if (isArmstrong(n)) cout << "YES" << endl;
    else cout << "NO" << endl;

return 0;
}