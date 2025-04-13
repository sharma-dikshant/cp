#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();

    vector<vector<int>>dp(n, vector<int>(2));  // [len, idx_of_last_el]

    for (int i = 0; i < n; i++) dp[i] = {1, -1};
    int res = 1;
    int idx = -1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (dp[j][0] + 1 > dp[i][0]) {
                    dp[i] = {dp[j][0] + 1, j};
                }
            }
        }

        if (dp[i][0] > res) {
            res = dp[i][0];
            idx = i;
        }
    }


    int i = idx;

    while (i != -1) {
        cout<<arr[i]<<" ";
        i = dp[i][1];
    }

    return 0;
}