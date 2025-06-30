/*
Problem: Inverted Triangle

Description:
Given an integer N, print an inverted triangle pattern with N rows. The first row should have N asterisks ('*') separated by a space,
and each subsequent row should have one less asterisk than the previous row, forming an inverted triangle.

Input:
- A single integer N (1 ≤ N ≤ 100) representing the number of rows in the triangle.

Output:
- The inverted triangle pattern, where each row contains the appropriate number of asterisks separated by a space.
- There should be no trailing spaces at the end of any line.

Example:
Input:
5

Output:
* * * * *
* * * *
* * *
* *
*

*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 0; j--) cout << '*';
        cout << endl;
    }

return 0;
}