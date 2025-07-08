/*
Problem Statement:
Given a string `s` and an integer `k`, find the length of the longest substring of `s` that contains at most `k` distinct characters.

Input:
- A string `s` consisting of lowercase English letters.
- An integer `k` representing the maximum number of distinct characters allowed in the substring.

Output:
- An integer representing the length of the longest substring of `s` that contains at most `k` distinct characters.

Constraints:
- 1 <= s.length <= 10^5
- 1 <= k <= 26

Example:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring "ece" contains 2 distinct characters and is the longest substring with at most 2 distinct characters.

Input: s = "aa", k = 1
Output: 2
Explanation: The substring "aa" contains 1 distinct character and is the longest substring with at most 1 distinct character.
*/



#include<bits/stdc++.h>
using namespace std;

int solve(string& s, int k) {
    int n = s.length(), res = -1;
    int i = 0, j = 0;
    unordered_map<char, int>mp;

    while (j < n) {
        mp[s[j]]++;

        while (!mp.empty() && mp.size() > k) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }

        res = max(res, j - i + 1);
        j++;
    }
    
    return res;
}

int main() {

    int k;
    cin>>k;
    string s;
    cin>>s;

    cout << solve(s, k) << endl;

return 0;
}