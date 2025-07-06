/*
Problem Statement: Minimize the Heights

Given an array `arr[]` denoting the heights of `N` towers and a positive integer `K`, you have the option to either increase or decrease the height of each tower by `K` (but only once for each tower). The task is to minimize the difference between the height of the tallest tower and the shortest tower after the modifications.

Constraints:
1. 1 <= N <= 10^5
2. 1 <= arr[i] <= 10^9
3. 1 <= K <= 10^9

Input:
- An integer `N` representing the number of towers.
- An array `arr[]` of size `N` representing the heights of the towers.
- An integer `K`.

Output:
- An integer representing the minimized difference between the tallest and shortest towers after the modifications.

Example:
Input:
N = 4, K = 3
arr[] = {1, 15, 10, 5}

Output:
8

Explanation:
After modifying the heights, the array becomes {4, 12, 7, 8}. The difference between the tallest and shortest towers is 12 - 4 = 8.
*/

//TODO best question

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin>>n>>k;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    int minn = arr[0];
    int maxx = arr[n - 1];
    int diff = maxx - minn;

    for (int i = 1; i < n; i++) {
        minn = min(arr[0] + k, arr[i] - k);
        maxx = max(arr[i - 1] + k, arr[n - 1] - k);

        diff = min(diff, maxx - minn);
    }

    cout << diff << endl;
    

return 0;
}