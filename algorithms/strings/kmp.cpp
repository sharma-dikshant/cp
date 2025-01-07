#include <bits/stdc++.h>
using namespace std;

void kmp(string txt, string pat, vector<int>& result) {
    if(txt.length() <= pat.length()) {
        if(txt == pat) {
            result.push_back(0);
        }
        return;
    }

    //calcutation for lps
    int t_len = txt.length();
    int p_len = pat.length();

    vector<int>lps(p_len, 0);
    
    //lps of single character is always zero
    lps[0] = 0;
    int i = 1, len = 0;

    while(i < p_len) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }else {
            if(len != 0) {
                len = lps[len - 1];
            }else {
                lps[i] = 0;
                i++;
            }
        }
    }

    //string comparison
    int j = 0;
    i = 0;

    while(i < t_len and j < p_len) {
        if(txt[i] == pat[j]) {
            i++;
            j++;

            if(j == p_len) {
                result.push_back(i - p_len); // push the index of first character of pat string in txt
                j = lps[j - 1];
            }
        }else {
            if(j != 0) {
                j = lps[j - 1];
            }else {
                i++;
            }
        }
    }
}

int main()
{
    string txt = "aabbabb";
    string pat = "abb";
    vector<int>result;

    kmp(txt, pat, result);
    for(auto el: result) {
        cout<<el<<" ";
    }
    return 0;
}