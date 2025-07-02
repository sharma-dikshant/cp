/*
Problem Statement: Left Rotate an Array by 1

Given an array of integers, write a function to left rotate the array by one position. 
The left rotation operation shifts each element of the array one position to the left, 
and the first element of the array is moved to the end.

Example:
Input: arr = [1, 2, 3, 4, 5]
Output: arr = [2, 3, 4, 5, 1]

Constraints:
1. The array will contain at least one element.
2. The elements of the array can be positive, negative, or zero.
3. The array size will not exceed 10^6.
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr) {
    int n = arr.size();
    if (n == 1) return arr;

    int f = arr[0];

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = f;

    return arr;
}

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    
    vector<int>res = solve(arr);

    for (auto el: res) cout << el << " ";

return 0;
}