/*
Problem Description: Reverse an Array

Given an array of integers, your task is to reverse the array. 
This means that the first element of the array becomes the last, 
the second element becomes the second last, and so on.

Input:
- An integer N, representing the size of the array (1 <= N <= 10^5).
- An array of N integers A[i] (-10^9 <= A[i] <= 10^9).

Output:
- The reversed array.

Example:
Input:
5
1 2 3 4 5
Output:
5 4 3 2 1

Explanation:
The input array [1, 2, 3, 4, 5] is reversed to [5, 4, 3, 2, 1].

Constraints:
- The array size N will be at most 100,000.
- The elements of the array can be large negative or positive integers.

Your task is to implement a function that efficiently reverses the array.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    int i = 0, j = n - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

return 0;
}