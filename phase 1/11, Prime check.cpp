// Problem Statement:
// Write a program to check whether a given number is a prime number or not.
// A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
// The program should take an integer input and output "Prime" if the number is prime, otherwise output "Not Prime".

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if (n == 1) cout << "Not Prime" << endl;
    bool isPrime = true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }

return 0;
}