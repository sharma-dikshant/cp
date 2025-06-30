/*
Problem: Pascal's Triangle

Description:
Pascal's Triangle is a triangular array of the binomial coefficients. In this problem, you are required to generate Pascal's Triangle with a specified number of rows. Each element in the triangle is the sum of the two directly above it (one directly above and one above to the left). The first and last elements of each row are always 1.

Input:
An integer, N, representing the number of rows in the triangle.

Output:
Print the first N rows of Pascal's Triangle. Each element within a row should be separated by a space.

Example:
Input:
5

Output:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Constraints:
0 <= N <= 15

Note:
Ensure each row is printed on a new line.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int>t;

    for (int r = 1; r <= n; r++) {
        // printing space
        int sp = n - r;
        while (sp--) cout << " ";

        vector<int>n_t(r);
        n_t[0] = n_t[r - 1] = 1;
        for (int i = 0; i < n_t.size(); i++) {
            if (i != 0 && i != r - 1) {
                n_t[i] = t[i - 1] + t[i];
            }
        }

        for (auto el: n_t) cout << el << " ";
        cout << endl;
        t = n_t;
    }

return 0;
}