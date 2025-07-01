/*
Problem Statement: Sieve of Eratosthenes

The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given integer `n`. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

Given an integer `n`, your task is to implement the Sieve of Eratosthenes algorithm to generate all prime numbers less than or equal to `n`.

Input:
- A single integer `n` (2 <= n <= 10^6).

Output:
- A list of all prime numbers less than or equal to `n`, in ascending order.

Example:
Input: 10
Output: 2, 3, 5, 7

Constraints:
- The algorithm should run efficiently within the given constraints.
- Avoid using nested loops with high time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<bool>sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (!sieve[i]) false;
        for (int j = i * 2; j < n; j += i) sieve[j] = false;
    }

    for (int i = 2; i < n; i++) {
        if (sieve[i]) cout << i << endl;
    }

return 0;
}