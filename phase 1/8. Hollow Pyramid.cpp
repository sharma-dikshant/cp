/*
Problem: Hollow Pyramid

Given an integer N, print a hollow pyramid pattern using asterisks (*). The pyramid should have N rows, where:
- The first row contains a single asterisk.
- The last row contains all asterisks with spaces in between.
- For rows 2 to N-1, only the first and the last positions are asterisks, and the positions in between are spaces.

The indentation for each row is such that the pyramid is centered. There should be no trailing spaces on any line.

Example:
Input: 5

Output:
    *
   * *
  *   *
 *     *
* * * * *
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;

    for (int r = 1; r < n; r++) {
        int sp = n - r;
        // print space 
        while (sp--) {
            cout << " ";
        }
        int st = r;
        // print first *
        cout << '*' << " "; st -= 1;
        while (st > 1) {
            cout << "  "; st--;
        }

        // print last *
        if (st == 1) cout << '*' << " ";

        cout << endl;
    }

    // printing last row
    for (int i = 1; i <= n; i++) cout << '*' << " ";

return 0;
}