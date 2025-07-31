#include<bits/stdc++.h>
using namespace std;

bool isPali(int i, int j, string& str) {
    while (i < j) {
        if (str[i] != str[j]) return false;
        i++; j--;
    }

    return true;
}

int main() {

    string str; cin>>str;
    string res = "";
    int len = 0;

    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            if ((j - i + 1) > len && isPali(i, j, str)) {
                len = j - i + 1;
                res = str.substr(i, len);
            }
        }
    }

    cout << res << endl;

return 0;
}