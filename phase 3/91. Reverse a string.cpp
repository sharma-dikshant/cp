/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

*/

#include<bits/stdc++.h>
using namespace std;

vector<char>solve1(vector<char>& arr) {

    int i = 0, j = arr.size() - 1;
    while (i < j) swap(arr[i++], arr[j--]);

    return arr;
}

void print(vector<char> arr) {
    for (auto el: arr) cout << el << " ";
    cout << endl;
}

int main() {

    int n; cin>>n;

    vector<char>arr(n);

    for (int i = 0; i < n; i++) cin>>arr[i];

    print(solve1(arr));

return 0;
}