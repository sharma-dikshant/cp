/*
Problem Statement: Square Root

Given a non-negative integer `x`, compute and return the square root of `x`. Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Constraints:
1. 0 <= x <= 2^31 - 1

Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

Note:
- You are not allowed to use any built-in exponent function or operator (such as `pow(x, 0.5)` or `x ** 0.5`).
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    int res = 0;
    int s = 1, e = n;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (mid * mid == n) {
            cout << mid << endl;
            return 0;
        } 

        if (mid * mid < n) {
            res = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout << res << endl;

return 0;
}

