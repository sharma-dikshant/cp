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
    int W = 7;
    
    vector<int>weights = {1, 3, 4, 5};
    vector<int>values = {1, 4, 5, 7};
    int n = weights.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            int skip = dp[i - 1][j];
            int take = 0;
            if (weights[i - 1] <= j) {
                take = values[i - 1] + dp[i - 1][j - weights[i - 1]];
            }
            dp[i][j] = max(skip, take);
        }
    }

    int res = dp[n][W];
    cout<<res<<endl;

    // printing selected items
    for (int i = n, w = W; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            //this item is contributed
            cout<<values[i - 1]<<" ";
            w -= weights[i - 1];
        }
    }

    return 0;
}