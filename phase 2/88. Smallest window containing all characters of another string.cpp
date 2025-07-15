/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include<bits/stdc++.h>
using namespace std;

string solve(string& s, string& t) {
    int n = s.length();
    int res = n + 1;
    string str = "";

    unordered_map<char, int>mp;
    for (auto& ch: t) {
        mp[ch]++;
    }

    int i = 0, j = 0, cnt = mp.size();

    while (j < n) {
        if (mp.count(s[j])) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) cnt--;
        }

        if (cnt == 0) {
            while (cnt == 0 && i <= j) {
                if (mp.count(s[i])) {
                    mp[s[i]]++;   
                    if (mp[s[i]] == 1) cnt++;
                }
                i++;
            }

            if ((j - i + 2) < res) {
                res = j - i + 2;
                str = s.substr(i - 1, res);
            }
        }

        j++;
    }

    return str;
}

int main() {

    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << endl;

return 0;
}