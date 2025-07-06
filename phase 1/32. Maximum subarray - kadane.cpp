/*
Problem Statement: Maximum Subarray Sum (Kadane's Algorithm)

Given an integer array `nums`, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The array contains only one element, so the maximum sum is 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The entire array has the largest sum = 23.

Constraints:
1. 1 <= nums.length <= 10^5
2. -10^4 <= nums[i] <= 10^4

Follow-up:
If you have already implemented the O(n) solution, try to implement it using divide and conquer, 
which is more subtle and has a time complexity of O(n log n).
*/

#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int>& arr) {
    int res = arr[0], n = arr.size(), sum = 0;

    for (auto el: arr) {
        sum += el;
        res = max(res, sum);
        if (sum < 0) sum = 0;
    }

    return res;
}

int main() {

    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    cout << sol1(arr) << endl;

return 0;
}