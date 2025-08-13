/*
Problem Statement: Union of Two Arrays

Given two arrays, `arr1` and `arr2`, your task is to find the union of these two arrays. 
The union of two arrays is a list that contains all the distinct elements from both arrays.

Input:
- Two arrays `arr1` and `arr2` of size `n` and `m` respectively.

Output:
- An array containing the union of the two input arrays. The output array should not contain duplicate elements.

Example:
Input:
arr1 = [1, 2, 3, 4]
arr2 = [3, 4, 5, 6]

Output:
[1, 2, 3, 4, 5, 6]

Constraints:
1. 1 <= n, m <= 10^5
2. 0 <= arr1[i], arr2[i] <= 10^9

Note:
- The order of elements in the output does not matter.
- Optimize the solution for time and space complexity.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int>arr1(n), arr2(m), res;

    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    unordered_set<int>st;

    for (int i = 0; i < n; i++) {
        if (st.find(arr1[i]) == st.end()) res.push_back(arr1[i]);
        st.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++) {
        if (st.find(arr2[i]) == st.end()) res.push_back(arr2[i]);
        st.insert(arr2[i]);
    }

    for (int& el: res) cout << el << " ";

return 0;
}