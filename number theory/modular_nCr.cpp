#include<iostream>
using namespace std;
typedef long long ll;

ll fact[51];
int MOD = 1e9 + 7;

int invFact(int n) {
    ll a = fact[n];
    int p = MOD - 2;
    ll res = 1;

    while (p) {
        if (p & 1) {
            res = (res % MOD * a % MOD) % MOD;
        }

        a = (a % MOD * a % MOD) % MOD; 
        p >>= 1;
    }

    return res % MOD;
}

ll nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0) return 1;
    if (r == 1) return n;
    if (r == n) return 1;

    // calculate nCr => fact(n) / fact(n - r) * fact(r)
    // using modular arithemetic => fact(n) % MOD * invFact(n - r) % MOD * invFact(r)

    return (fact[n] % MOD * invFact(n - r) % MOD * invFact(r) % MOD) % MOD;
}

int main() {

    // pre-compute factorial
    fact[0] = fact[1] = 1;

    for (int i = 2; i < 51; i++) {
        fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
    }

    cout << nCr(4, 2) << endl;

return 0;
}