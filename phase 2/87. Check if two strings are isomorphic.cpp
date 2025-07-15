/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true



Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include<bits/stdc++.h>
using namespace std;

string mapping(string s) {
    char map[260] = { 0 };      // maxium ascii characters are 256  8-bit
    char st = '0';
    for (auto& ch: s) {
        if (map[ch] == 0) {
            map[ch] = st;
            st++;
        }
    }

    for (int i = 0; i < s.length(); i++) {
        char ch = map[s[i]];
        s[i] = ch;
    }

    return s;
}

bool solve(string& s, string& t) {
    if (s.length() != t.length()) return false;

    return mapping(s) == mapping(t);
}

int main() {

    string s, t;
    cin>>s>>t;

    cout << solve(s, t) << endl;

return 0;
}