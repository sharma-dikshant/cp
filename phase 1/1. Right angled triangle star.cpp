/*
    Problem: Right Angled Triangle Star

    Description:
    Write a program that prints a right angled triangle pattern using the star (*) character.
    The program should prompt the user for an integer n, which represents the number of rows.
    For each row i (1 ≤ i ≤ n), the program should print exactly i stars.
    For example, if the user enters 5, the output should be:
    *
    **
    ***
    ****
    *****

    Input:
    - A single integer n (the number of rows for the triangle).

    Output:
    - A right angled triangle pattern of stars, where row i contains i stars.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << "*";
        cout << "\n";
    }

return 0;
}