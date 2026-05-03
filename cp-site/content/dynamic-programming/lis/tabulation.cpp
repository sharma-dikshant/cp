#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();
    vector<int>dp(n, 1);
    int res = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { 
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        res = max(res, dp[i]);
    }

    cout<<res;

    return 0;
}