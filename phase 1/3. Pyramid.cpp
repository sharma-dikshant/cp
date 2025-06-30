/*
Problem: Pyramid Problem

Description:
    Given a number of rows (n), print a pyramid pattern using asterisk (*) characters.
    The pyramid pattern is structured so that the first row has one star, the second row has two stars,
    and so on up to the base of the pyramid having n stars. The stars must be properly centered to form
    a symmetric pyramid.

Input:
    A single integer n (1 <= n <= 50) representing the number of rows.

Output:
    Print the pyramid pattern with n rows. Each row should be centered and no trailing spaces must exist.

Example:

Input:
5

Output:
        *
       * *
      * * *
     * * * *
    * * * * *
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    for (int row = 1; row <= n; row++) {
        // leave left spaces 
        int t = n - row;
        while (t--) cout << " ";

        //print stars
        int s = row;
        while (s--) cout << "*" << " ";

        cout << endl;
    }

return 0;
}