/*
Problem Statement: Left Rotate by D

Given an array of integers `arr` of size `n` and an integer `D`, your task is to rotate the array to the left by `D` positions. The rotation should be performed in-place, and the resulting array should maintain the order of elements after the rotation.

Input:
- An integer `n` representing the size of the array (1 <= n <= 10^5).
- An integer `D` representing the number of positions to rotate the array (0 <= D <= n).
- An array `arr` of size `n` containing integers (-10^9 <= arr[i] <= 10^9).

Output:
- The modified array after performing the left rotation by `D` positions.

Example:
Input:
n = 5, D = 2
arr = [1, 2, 3, 4, 5]

Output:
[3, 4, 5, 1, 2]

Explanation:
After rotating the array [1, 2, 3, 4, 5] to the left by 2 positions, the resulting array is [3, 4, 5, 1, 2].

Constraints:
- The rotation should be performed in-place with O(1) additional space.
- The solution should have a time complexity of O(n).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sol1(vector<int>arr, int d) {
    int n = arr.size();
    vector<int>t(n);

    for (int i = 0; i < n; i++) {
        t[(n + i - d) % n] = arr[i];
    }

    return t;
}

vector<int> sol2(vector<int>arr, int d) {
    int prev = arr[0];
    int t = 0, n = arr.size(), i = 0;

    while (t < n) {
        int idx = (n + i - d) % n;
        int x = arr[idx];

        arr[idx] = prev;
        prev = x;
        i = idx;
        t++;
    }

    return arr;
}

int main() {

    int n,d;
    cin>>n>>d;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    
    // arr = sol1(arr, d);
    arr = sol2(arr, d);
    for (auto el: arr) cout << el << " ";

return 0;
}