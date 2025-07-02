/*
Problem Statement: Remove Duplicates

Given a sorted array `nums`, remove the duplicates in-place such that each element appears only once and return the new length. 
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some programming languages, you must instead have the result 
be placed in the first part of the array `nums`. More formally, if there are `k` elements after removing the duplicates, 
then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively. 
It does not matter what you leave beyond

*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    int j = -1;
    for (int i = 0; i < n; i++) {
        if (j == -1 || arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    for (auto el: arr) cout << el << " ";

return 0;
}