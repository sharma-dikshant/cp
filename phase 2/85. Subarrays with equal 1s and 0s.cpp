/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    unordered_map<int, int>mp;
    int res = 0, n = arr.size(), curr = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i]) curr += 1;
        else curr -= 1;

        if (curr == 0) res = max(res, i + 1);

        int req = curr;
        if (mp.count(req)) {
            res = max(res, i - mp[req]);
        }

        if (!mp.count(curr)) mp[curr] = i;
    }

    return res;
}

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) cin>>arr[i];

    cout << solve(arr) << endl;

return 0;
}