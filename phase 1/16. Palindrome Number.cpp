/*
Problem: Palindrome Number

Description:
A palindrome is a number that reads the same backward as forward. For example, 121 is a palindrome, but 123 is not.

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

Constraints:
1. The input integer `x` can be negative, zero, or positive.
2. Negative numbers are not considered palindromes.
3. You are not allowed to convert the integer into a string or use extra space.

Examples:
1. Input: x = 121
    Output: true
    Explanation: 121 reads the same backward as forward.

2. Input: x = -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore, it is not a palindrome.

3. Input: x = 10
    Output: false
    Explanation: Reads 01 from backward, which is not the same as 10.

4. Input: x = 0
    Output: true
    Explanation: 0 reads the same backward as forward.

Write a function to determine whether the given integer is a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

bool withoutUsingString(int n) {
    int reverse = 0;
    while (n) {
        reverse = reverse * 10 + n % 10;
        if (reverse == n) return true;
        if (reverse > n) break;
        n /= 10;
        if (reverse == n) return true;
    }

    return false;
}

int main() {

    int n;
    cin>>n;

    if (n < 0) {
        n *= -1;
    }

    string s2 = to_string(n);
    string s1 = s2;
    reverse(s2.begin(), s2.end());

    if (s1 == s2) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    cout << withoutUsingString(n) << endl;

return 0;
}

