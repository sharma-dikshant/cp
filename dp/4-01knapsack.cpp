#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int solve (vector<int>& w, vector<int>& v, int idx, int W) {
    if (idx < 0 || W == 0) {
        return 0;
    }

    if (dp[idx][W] != -1) return dp[idx][W];

    int skip = solve(w, v, idx - 1, W);
    int take = -1;
    if (w[idx] <= W) {
        take = v[idx] + solve(w, v, idx - 1, W - w[idx]);
    }

    return dp[idx][W] = max(take, skip);
}

int main() {
    memset(dp, -1, sizeof(dp));
    int W = 100;
    vector<int> weights(500), values(500);
    int n = weights.size();
    for (int i = 0; i < 500; ++i) {
        weights[i] = i + 1;         // 1 to 500
        values[i] = 500 - i;        // 500 to 1
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            int skip = dp[i - 1][j];
            int take = 0;
            if (weights[i - 1] <= j) {
                take = values[i - 1] + dp[i - 1][j - weights[i - 1]];
            }
            dp[i][j] = max(skip, take);
        }
    }

    int res = dp[n][W];
    cout<<res;

    // cout<<solve(weights, values, n - 1, W);
    return 0;
}