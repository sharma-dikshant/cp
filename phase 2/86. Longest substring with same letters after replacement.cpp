/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/


#include<bits/stdc++.h>
using namespace std;

int valid(vector<int> alpha, int k) {
    sort(alpha.begin(), alpha.end());

    for (int i = 0; i < alpha.size() - 1; i++) {
        k -= alpha[i];
        if (k < 0) return false;
    }

    return true;
}

int solve(string& s, int k) {
    int res = 0, n = s.length();
    vector<int>alpha(26, 0);

    int i = 0, j = 0, cnt = 0;

    while (j < n) {
        if (alpha[s[j] - 'A'] == 0) cnt++;
        alpha[s[j] - 'A']++;

        while (cnt > 1 && !valid(alpha, k)) {
            alpha[s[i] - 'A']--;
            if (alpha[s[i] - 'A'] == 0) cnt--;
            i++;
        }
        
        res = max(res, j - i + 1);
        j++;
    }

    return res;
}

int main() {

    string s;
    int k;
    cin>>s;
    cin>>k;

    cout << solve(s, k) << endl;

return 0;
}