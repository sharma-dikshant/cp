/*
Problem Statement: Sum of Digits

Given a non-negative integer `n`, write a program to calculate the sum of its digits.

Input:
- A single non-negative integer `n` (0 <= n <= 10^9).

Output:
- A single integer representing the sum of the digits of `n`.

Example:
Input: 123
Output: 6

Explanation:
The sum of the digits of 123 is 1 + 2 + 3 = 6.

Input: 0
Output: 0

Explanation:
The sum of the digits of 0 is 0.

Constraints:
- The input number `n` will always be a non-negative integer.
*/


#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    int t = 0;
    while (n) {
        t += n % 10;
        n /= 10;
    }

    cout << t << endl;

return 0;
}