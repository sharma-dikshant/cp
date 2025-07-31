/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.



Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    string str; cin>>str;
    int k; cin>>k;

    stack<pair<char, int>>st;   // ch, fre

    for (char ch: str) {
        if (st.empty()) {
            st.push({ ch, 1 });
            continue;
        }

        if (st.top().first == ch) {
            st.push({ ch, st.top().second + 1 });
        } else {
            st.push({ ch, 1 });
        }

        if (st.top().second == k) {
            int t = k;
            while (t--) st.pop();
        }
    }


    string res = "";
    while (!st.empty()) {
        res += st.top().first;
        st.pop();
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

return 0;
}