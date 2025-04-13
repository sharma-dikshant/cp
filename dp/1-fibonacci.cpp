#include <bits/stdc++.h>
using namespace std;

long long t[100000];
long long fib(int n) {
    if (n <= 1) return n;
    if (t[n] != -1) return t[n];
    return t[n] = fib(n - 1) + fib(n - 2);
}
int main() {
    memset(t, -1, sizeof(t));
    int n;
    cin>>n;
    vector<long long>dp(n + 1, 0);
    // cout<<fib(n);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout<<dp[n];

    return 0;
}