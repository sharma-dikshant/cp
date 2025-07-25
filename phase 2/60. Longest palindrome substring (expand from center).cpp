/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPali(string& s, int i, int j) {
    int x = i, y = j;
    while (i < j) {
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i++] != s[j--]) return dp[x][y] = false;
    }

    return dp[x][y] = true;
}

int main() {
    memset(dp, -1, sizeof(dp));
    string s; cin >> s;

    int res = 0;
    string res_s = "";

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if ((j - i + 1 > res) && isPali(s, i, j)) {
                res = j - i + 1;
                res_s = s.substr(i, res);
            }
        }
    }

    cout << res_s << endl;

return 0;
}