/*
Problem Statement: Second Largest Element

Given an array of integers, your task is to find the second largest element in the array. 
If the array has fewer than two distinct elements, return an appropriate value or message indicating that the second largest element does not exist.

Input:
- An integer array `arr` of size `n` (1 <= n <= 10^5).
- The elements of the array can be positive, negative, or zero.

Output:
- The second largest distinct element in the array.
- If no such element exists, return an appropriate message or value.

Example 1:
Input: arr = [10, 20, 4, 45, 99]
Output: 45

Example 2:
Input: arr = [10, 10, 10]
Output: "Second largest element does not exist"

Constraints:
- The solution should have a time complexity of O(n).
- The array may contain duplicate elements.
*/


#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    if (n < 2 || (n == 2 && (arr[0] == arr[1]))) {
        cout << "Invalid!" << endl;
        return 0;
    }

    queue<int>q;

    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            q.push(arr[i]); continue;
        } 

        if (arr[i] > q.back()) {
            if (q.size() == 2) q.pop(); 
            q.push(arr[i]);
        }
    }

    if (q.size() < 2) {
        cout << "Second largest element not exist!" << endl;
        return 0;
    } 
    cout << q.front() << endl;

return 0;
}