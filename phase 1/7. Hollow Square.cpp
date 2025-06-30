/*
Problem: Hollow Square

Description:
Given an integer n representing the side length of a square, write a program to print a hollow square pattern. The square's border should be filled with asterisks ('*'), while the inside should be empty (filled with spaces).

Input:
- An integer n, the size of the square.

Output:
- A hollow square pattern of dimensions n x n.

Example:
If n = 5, the output should be:
*****
*   *
*   *
*   *
*****

Constraints:
- 1 <= n <= 100

Note:
- The first and last rows must be completely filled with asterisks.
- For all other rows, the first and last characters should be asterisks, with spaces in between.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }

return 0;
}