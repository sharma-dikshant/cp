#include<iostream>
using namespace std;

typedef long long ll;

int main() {

    int N = 51;
    int MOD = 1e9 + 7;
    vector<ll>factorial(N);
    factorial[0] = factorial[1] = 1;

    for (ll i = 2; i < N; i++) {
        factorial[i] = ((factorial[i - 1] % MOD) * (i % MOD)) % MOD;
    }

    for (int i = 2; i < N; i++) cout << factorial[i] << " ";
    return 0;
}