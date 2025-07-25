/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;
    vector<string>arr(n);

    for (int i = 0; i < n; i++) cin>>arr[i];

    int len = INT_MAX;
    string pref = "";

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = 0;
            while (x < arr[i].length() && x < arr[j].length() && arr[i][x] == arr[j][x]) x++;
            if (x == 0) {
                len = 0;
                pref = "";
                break;
            }

            if (x < len) {
                len = x;
                pref = arr[i].substr(0, len);
            }
        }

        break;
    }

    cout << pref << endl;

return 0;
}