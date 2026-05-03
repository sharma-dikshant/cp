#include <bits/stdc++.h>
using namespace std;

int t[10000][10000];

int solve (vector<int>& arr, int idx, int prev) {
    if (idx == arr.size()) return 0;

    if (t[idx][prev + 1] != -1) return t[idx][prev + 1];
    int skip = solve(arr, idx + 1, prev);
    int take = 0;

    if (prev == -1 || arr[idx] > arr[prev]) {
        take = 1 + solve(arr, idx + 1, idx);
    }

    return t[idx][prev + 1] = max(skip, take);
}

int main() {
    memset(t, -1, sizeof(t));
    vector<int>arr = {10,9,2,5,3,7,101,18};

    cout<<solve(arr, 0, -1);

    return 0;
}