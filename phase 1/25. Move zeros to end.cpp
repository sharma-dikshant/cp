/*
Problem Statement:
Given an array of integers, write a function to move all the zeros in the array to the end while maintaining the relative order of the non-zero elements. The operation should be performed in-place without using extra space for another array.

Input:
- An array of integers `nums` of size `n`.

Output:
- The modified array with all zeros moved to the end.

Constraints:
- The array may contain positive, negative, and zero values.
- Try to achieve the solution with O(n) time complexity and O(1) space complexity.

Example:
Input : nums = [0, 1, 0, 3, 12]
Output: nums = [1, 3, 12, 0, 0]

Input : nums = [0, 0, 1]
Output: nums = [1, 0, 0]
*/

#include<bits/stdc++.h>
using namespace std;

void sol1(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    int j = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            int x = i;
            while (x < j) {
                swap(arr[x], arr[x + 1]);
                x++;
            }
            j--;
        }
    }
}

//TODO optimum O(n) O(1) 

int main() {


    int n;
    cin>>n;
    vector<int>arr(n);

    for (int i = 0; i < n; i++) cin>>arr[i];
    sol1(arr);

    for (auto el: arr) cout << el << " ";


return 0;
}