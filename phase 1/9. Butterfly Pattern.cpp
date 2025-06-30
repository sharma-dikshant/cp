// Problem Statement: Butterfly Pattern

/*
Write a program to print a butterfly pattern of stars (*) for a given number of rows, `n`.

The butterfly pattern consists of two mirrored triangles (upper and lower) that form a butterfly-like shape. 
For example, for n = 4, the pattern should look like this:

*      *
**    **
***  ***
********
********
***  ***
**    **
*      *

Input:
- An integer `n` representing the number of rows for the upper half of the butterfly.

Output:
- The butterfly pattern printed to the console.

Constraints:
- 1 <= n <= 50
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;

    // printing upper half
    int r = 1;
    for (; r <= n; r++) {
        // printing start
        for (int s = 1; s <= r; s++) cout << '*';

        int sp = (n - r) * 2;
        while (sp--) cout << ' ';

        // printing last
        for (int s = 1; s <= r; s++) cout << '*';

        cout << endl;
    }

    r -= 1;

    for (; r > 0; r--) {
        // printing start
        for (int s = 1; s <= r; s++) cout << '*';

        int sp = (n - r) * 2;
        while (sp--) cout << ' ';

        // printing last
        for (int s = 1; s <= r; s++) cout << '*';

        cout << endl;
    }



return 0;
}