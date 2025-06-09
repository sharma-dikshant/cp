#include<bits/stdc++.h>
using namespace std;

int main() {

    string input;
    cin>>input;
    int n = input.size();
    unordered_map<char, int>mp;
    for (char c: input) {
        mp[c]++;
    }

    int cnt = 0;
    for (auto el: mp) {
        if (n % 2 == 0 && el.second % 2 == 1) {  // size is even && fre is odd
            cout << "NO SOLUTION" << endl;
            return 0;
        } else if (n % 2 == 1 && el.second % 2 == 1) { // size is odd && fre is odd
            cnt++;
        }

        if (cnt == 2) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    int i = 0, j = n - 1;
    char mid;
    for (auto el: mp) {
        while (el.second > 1) {
            input[i] = input[j] = el.first;
            i++; j--;
            el.second -= 2;
        }
        if (el.second == 1) {
            mid = el.first;
        }
    }

    if (i == j) input[i] = mid;

    cout << input << endl;

return 0;
}