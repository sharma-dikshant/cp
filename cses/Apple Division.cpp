#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(int idx, ll curr, ll t_sum, vector<int>& arr) {
    if (idx == arr.size()) {
        return abs(curr - t_sum);
    }

    ll take = solve(idx + 1, curr + arr[idx], t_sum - arr[idx], arr);
    ll skip = solve(idx + 1, curr, t_sum, arr);

    return min(take, skip);
}

int main() {

    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    ll t_sum = accumulate(arr.begin(), arr.end(), 0LL);
    cout << solve(0, 0, t_sum, arr) << endl;

return 0;
}