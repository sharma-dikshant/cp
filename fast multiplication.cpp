#include<bits/stdc++.h>
using namespace std;

int multiply(int a, int b, int c) {
    int res = 0;

    while (b) {
        if (b & 1) res += a;

        a *= 2;
        b /= 2;
    }

    return res;
}

int main() {

    /**
        let 3 number a, b, c
        and a, b, c <= 10^15
        we've to calculate (a * b) % c

        three possible solutions are
        0. one more possiblity is -> ((a % c) * (b % c)) % c
        1. brute force -> directly solve : but it would'nt work as it exceeds even unsigned long long limit
        2. string solution -> O(log(a) * log(b)) = O(log(a * b))
        3. fast multiplication
     */

     cout << multiply(25, 7, 1) << endl;

return 0;
}