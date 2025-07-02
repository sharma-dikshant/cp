/*
Problem Statement: Leaders in an Array

Given an array of integers `arr` of size `n`, a leader is an element that is strictly greater than all the elements to its right in the array. The rightmost element is always considered a leader.

Your task is to write a program to find all the leaders in the array and print them in the order they appear in the array.

Input:
- An integer `n` representing the size of the array (1 <= n <= 10^6).
- An array `arr` of size `n` containing integers (-10^7 <= arr[i] <= 10^7).

Output:
- A list of integers representing the leaders in the array.

Example:
Input:
n = 6
arr = [16, 17, 4, 3, 5, 2]

Output:
17 5 2

Explanation:
- 17 is greater than all elements to its right.
- 5 is greater than all elements to its right.
- 2 is the last element, so it is a leader.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    vector<int>leader;
    leader.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > leader.back()) leader.push_back(arr[i]);
    }

    for (int i = leader.size() - 1; i >= 0; i--) cout << leader[i] << " ";

return 0;
}