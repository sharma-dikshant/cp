/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3

Example 4:
Input: nums = [9,1,4,7,3,-1,0,5,8,-1,6]
Output: 7

*/

#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int> arr) {
    /* using sorting */
    int n = arr.size();
    if (n == 0) return 0;
    sort(arr.begin(), arr.end());
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        int cnt = 1;
        while (i < n - 1 && abs(arr[i] - arr[i + 1]) <= 1) {
            if (arr[i] != arr[i + 1]) cnt++;
            i++;
        }

        res = max(res, cnt);
    }

    return res;
}

int sol2(vector<int> arr) {
    /* using set */
    int n = arr.size();
    if (n == 0) return 0;

    set<int>st;
    for (auto el: arr) st.insert(el);

    int res = 1, cnt = 0, prev = *st.begin();

    for (int el: st) {
        if (abs(el - prev) > 1) {
            res = max(res, cnt);
            cnt = 1;
        } else {
            cnt++;
        }

        prev = el;
    }

    res = max(res, cnt);

    return res;
}

int sol3(vector<int> arr) {
    /* Using hash map */

    unordered_map<int, bool>mp;
    for (auto el: arr) mp[el] = true;

    for (int i = 0; i < arr.size(); i++) {
        if (mp.count(arr[i] - 1)) mp[arr[i]] = false;   // start the new seq from arr[i]
    }

    int res = 0;
    for (auto& el: mp) {
        if (el.second) {
            int cnt = 1;
            while (mp.count(el.first + cnt)) cnt++;
            res = max(res, cnt);
        }
    }

    return res;
}

int main() {

    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    cout << sol1(arr) << endl;
    cout << sol2(arr) << endl;
    cout << sol3(arr) << endl;


return 0;
}