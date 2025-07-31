/*
Problem Statement:
------------------
Given two strings, s1 and s2, write a function to check if s2 is a rotation of s1. A string s2 is considered a rotation of s1 if it can be obtained by shifting the characters of s1 in a circular manner.

For example:
- "abcd" and "dabc" are rotations of each other.
- "abcd" and "cdab" are rotations of each other.
- "abcd" and "bcda" are rotations of each other.
- "abcd" and "acbd" are NOT rotations of each other.

Input:
- Two strings, s1 and s2.

Output:
- Return true if s2 is a rotation of s1, otherwise return false.

Constraints:
- The lengths of s1 and s2 must be equal for s2 to be a rotation of s1.
- Both strings consist of printable ASCII characters.
*/



#include<bits/stdc++.h>
using namespace std;

bool stringMatch(string& txt, string& pat) {
    int t = txt.length(), p = pat.length();

    vector<int>lps(p, 0);

    int i = 1, len = 0;

    while (i < p) {
        if (pat[i] == pat[len]) {
            len++; i++;
            lps[i] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int j = 0;
    i = 0;

    while (j < t) {
        if (txt[j] == pat[i]) {
            j++; i++;
            if (i == p) return true;
        } else {
            if (i != 0) {
                i = lps[i - 1];
            } else {
                j++;
            }
        }
    }


    return false;
}

int main() {

    string s1, s2;
    cin>>s1>>s2;

    string txt = s1 + s2;

    if (txt.find(s2) != string::npos) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    cout << stringMatch(txt, s2) << endl;

    return 0;
}