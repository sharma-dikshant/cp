#include<bits/stdc++.h>
using namespace std;

void solve(string& curr, int n, vector<string>& res) {
    if (curr.size() == n) {
        res.push_back(curr);
        return;
    }

    // add 0
    curr += '0';
    solve(curr, n, res);
    curr.pop_back();

    // add 1
    curr += '1';
    solve(curr, n, res);
    curr.pop_back();
}

int main() {

    vector<string>res = {"0", "1"};
    int n;
    cin>>n;
    n--;
    while (n--) {
        vector<string>temp;
        // append 0
        for (int i = 0; i < res.size(); i++) {
            temp.push_back((res[i] + '0'));
        }
        // append 1
        for (int i = res.size() - 1; i >= 0; i--) {
            temp.push_back((res[i] + '1'));
        }

        res = temp;
    }

    for (auto el: res) {
        cout << el << endl;
    }

return 0;
}