/*
Problem Statement: Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique, and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1. 1 <= nums1.length, nums2.length <= 1000
2. 0 <= nums1[i], nums2[i] <= 1000

Follow-up:
1. What if the given arrays are sorted? How would you optimize your algorithm?
2. What if nums1's size is small compared to nums2's size? Which algorithm is better suited for this case?
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int>arr1(n), arr2(m), res;

    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            res.push_back(arr1[i]);
            i++; j++;
            continue;
        }

        if (arr1[i] < arr2[j]) i++;
        else j++;
    }


    for (int& el: res) cout << el << " ";


return 0;
}