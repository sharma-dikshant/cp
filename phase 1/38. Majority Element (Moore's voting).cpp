/*
Problem Statement: Majority Element

Given an array `nums` of size `n`, find the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
1. `n == nums.length`
2. `1 <= n <= 5 * 10^4`
3. `-10^9 <= nums[i] <= 10^9`

Follow-up: Could you solve the problem in O(n) time and O(1) space using Moore's Voting Algorithm?
*/


#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int>& arr) {
    int c = arr[0], cnt = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == c) cnt++;
        else cnt--;

        if (cnt == 0) {
            c = arr[i];
            cnt = 1;
        }
    }

    return c;
}

int main() {

    int n; cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];


    int res = -1;
    unordered_map<int, int>mp;

    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] >= n / 2) {
            res = arr[i];
            break;
        }
    }
    

    cout << res << endl;
    cout << optimal(arr) << endl;

return 0;
}