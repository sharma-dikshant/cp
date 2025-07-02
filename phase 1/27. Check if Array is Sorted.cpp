/*
Problem Statement:
------------------
Write a function to check if a given array is sorted in non-decreasing order. 
An array is considered sorted if for every pair of consecutive elements, 
the first element is less than or equal to the second element.

Input:
- An integer array `arr` of size `n` (1 <= n <= 10^5).
- The array elements can be positive, negative, or zero.

Output:
- Return `true` if the array is sorted in non-decreasing order, otherwise return `false`.

Examples:
---------
Example 1:
Input: arr = [1, 2, 2, 3]
Output: true

Example 2:
Input: arr = [4, 3, 2, 1]
Output: false

Example 3:
Input: arr = [5]
Output: true

Constraints:
------------
- The function should run in O(n) time complexity.
- The function should use O(1) additional space.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    int flag = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] < flag) {
            cout << "False" << endl;
            return 0;
        }

        flag = max(flag, arr[i]);
    }

    cout << "True" << endl;

return 0;
}