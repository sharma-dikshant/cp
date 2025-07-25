#include<bits/stdc++.h>
using namespace std;

int main() {

    int n; cin>>n;

    map<int, string>mp = {
      {1, "I"},
      {4, "IV"},
      {5, "V"},
      {9, "IX"},
      {10, "X"},
      {40, "XL"},
      {50, "L"},
      {90, "XC"},
      {100, "C"},
      {400, "CD"},
      {500, "D"},
      {900, "CM"},
      {1000, "M"},
    };

    string res = "";

    while (n) {
        auto it = mp.lower_bound(n);
        if (it->first != n) {
            it = prev(it);
        }
        int cnt = n / it->first;
        while (cnt--) res += it->second;
        n %= it->first;
    }

    cout << res << endl;

return 0;
}