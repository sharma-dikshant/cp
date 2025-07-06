/*
Problem Statement:
You are given two sorted arrays, `arr1` and `arr2`, of sizes `n` and `m` respectively. Your task is to merge these two arrays into a single sorted array.

Input:
- `arr1`: A sorted array of integers of size `n`.
- `arr2`: A sorted array of integers of size `m`.

Output:
- A single sorted array containing all the elements of `arr1` and `arr2`.

Example:
Input:
arr1 = [1, 3, 5]
arr2 = [2, 4, 6]

Output:
[1, 2, 3, 4, 5, 6]

Constraints:
- 1 <= n, m <= 10^5
- -10^9 <= arr1[i], arr2[i] <= 10^9
- Both `arr1` and `arr2` are sorted in non-decreasing order.
*/


#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin>>n>>m;

    vector<int>arr1(n), arr2(m), res(n + m);

    for (int i = 0; i < n; i++) cin>>arr1[i];
    for (int i = 0; i < m; i++) cin>>arr2[i];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            res[k++] = arr1[i++];
        } else {
            res[k++] = arr2[j++];
        }
    }

    while (i < n) res[k++] = arr1[i++];
    while (j < m) res[k++] = arr2[j++];

    for (auto el: res) cout << el << " ";

return 0;
}