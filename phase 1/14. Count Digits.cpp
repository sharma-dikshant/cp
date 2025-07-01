// Problem: Count Digits
// Description:
// Given an integer `n`, write a program to count the number of digits in the given number.
// The program should handle both positive and negative integers.
//
// Input:
// - A single integer `n`.
//
// Output:
// - An integer representing the count of digits in the absolute value of `n`.
//
// Constraints:
// - -10^9 <= n <= 10^9
//
// Example:
// Input: 12345
// Output: 5
//
// Input: -9876
// Output: 4
//
// Note:
// The program should not use any string conversion methods to count the digits.

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (n < 0) n *= -1;

    int digits = log10(n) + 1;
    cout << digits << endl;


return 0;
}