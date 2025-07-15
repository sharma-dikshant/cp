/*
Problem Statement: Count Pairs with Given Sum in Array

Given an array of integers `arr` and an integer `targetSum`, your task is to find the number of unique pairs of elements in the array whose sum is equal to the given `targetSum`.

Input:
- An integer array `arr` of size `n` (1 <= n <= 10^5).
- An integer `targetSum` (-10^9 <= targetSum <= 10^9).

Output:
- An integer representing the count of pairs whose sum equals `targetSum`.

Note:
- A pair (arr[i], arr[j]) is considered valid if i < j.
- The array may contain duplicate elements.
- The solution should have an efficient time complexity.

Example:
Input: arr = [1, 5, 7, -1], targetSum = 6
Output: 2
Explanation: The pairs are (1, 5) and (7, -1).

Input: arr = [1, 1, 1, 1], targetSum = 2
Output: 6
Explanation: The pairs are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), and (1, 1).
*/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int target) {
    int res = 0;
    unordered_map<int, int>mp;

    for (auto& el: arr) {
        if (mp.count(target - el)) {
            res += mp[target - el];
        }
        mp[el]++;
    }

    return res;
}

int main() {

    int n, target;
    cin>>n>>target;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) cin>>arr[i];

    cout << solve(arr, target) << endl;

return 0;
}