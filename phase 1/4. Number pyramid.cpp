/*
Problem: Number Pyramid

Description:
Write a program that prints a number pyramid. The pyramid should have a specified number of rows,
and each row should contain increasing numbers starting from 1 up to the row number.
The numbers in each row should be properly spaced to form a pyramid shape when output.

Example:
For an input of n = 5, the pyramid should look like:

        1
       1 2
      1 2 3
     1 2 3 4
    1 2 3 4 5

Input:
- A single integer n, where n represents the number of rows in the pyramid.

Output:
- The number pyramid as described, with each row centered.

Constraints:
- 1 <= n <= 100 (you may assume a reasonable limit to avoid excessive output)

Note:
- Ensure that the spacing is correct so that the pyramid shape is maintained.
- You may use loops to generate the numbers and spaces.

*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;

    for (int row = 1; row <= n; row++) {
        // printing space
        int t = n - row;
        while(t--) cout << " ";

        // printing number
        t = 1;
        while (t <= row) cout << t++ << " ";

        cout << endl;
    }

return 0;
}