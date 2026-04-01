#include<iostream>
using namespace std;

int factorial[15];
int MOD = 1e9 + 7;

int nCr(int n, int r) {
    if (r > n) return 0;
    if (n == r) return 1;

    return factorial[n] / (factorial[n - r] * factorial[r]);
}

int main() {

    factorial[0] = factorial[1] = 1;

    for (int i = 2; i < 15; i++) {
        factorial[i] = (factorial[i - 1] % MOD * i % MOD) % MOD;
    }

    cout << factorial[10] << endl;
    cout << nCr(15, 2) << endl;

    return 0;
}