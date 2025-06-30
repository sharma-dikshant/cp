/*
    Diamond Pattern Problem

    Problem Statement:
    Given an integer n, write a program to print a diamond pattern of asterisks (*) with a total of (2*n - 1) rows. 
    The pattern consists of an upper part where the number of asterisks in each row increases from 1 to (2*n - 1), 
    followed by a lower part where the number of asterisks decreases back to 1.

    Input:
    An integer n, representing the number of rows in the upper half of the diamond.

    Output:
    A diamond-shaped pattern printed using spaces and asterisks. 

    Example:
    For n = 5, the output should be:
              *
             * *
            * * *
           * * * *
          * * * * *
           * * * *
            * * *
             * *
              *

    Constraints:
    1 <= n <= 100

    Note:
    Ensure that proper spacing is maintained to achieve the symmetry of the diamond shape.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;

    // printing upward
    int i = 1;
    for (; i <= n; i++) {
        int t = n - i;
        while (t--) cout << " ";
        // print *
        t = i;
        while (t--) cout << '*' << " ";
        cout << endl;
    }

    i -= 2;

    for (; i > 0; i--) {
        int t = n - i;
        while (t--) cout << " ";
        // print *
        t = i;
        while (t--) cout << '*' << " ";
        cout << endl;
    }

return 0;
}