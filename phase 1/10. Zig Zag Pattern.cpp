/*
Problem Description:
The Zig Zag Pattern problem involves printing a pattern in a zig-zag shape for a given number of rows and columns. The pattern alternates between moving diagonally downwards and upwards, creating a zig-zag effect.

For example, given a number of rows `r` and columns `c`, the output should look like:

r = 3, c = 7
      *     *    *
       *  *  *  *
        *     *

The pattern starts at the top-left corner, moves diagonally downwards, and then diagonally upwards repeatedly until the specified number of columns is reached.

Constraints:
- 1 <= r <= 100 (number of rows)
- 1 <= c <= 100 (number of columns)

The task is to implement a function that generates and prints this zig-zag pattern.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int r, c; cin>>r>>c;

    vector<vector<char>>grid(r, vector<char>(c, ' '));

    int i = 0, dir = 0;
    for (int j = 0; j < c; j++) {
        grid[i][j] = '*';
        if (dir) i--; // 1 -> upward
        else i++;

        if (i == r) {
            i -= 2;
            dir = 1;
        } else if (i == -1) {
            i += 2;
            dir = 0;
        }
    }

    for (auto g: grid) {
        for (auto ch: g) cout << ch;
        cout << endl;
    }

return 0;
}