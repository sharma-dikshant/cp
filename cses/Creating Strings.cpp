#include<bits/stdc++.h>
using namespace std;

void solve(int idx, string& curr, vector<char>& arr, vector<string>& res) {
    if (idx == arr.size()) {
        res.push_back(curr);
        return;
    }

    unordered_set<char>st;
    for (int i = 0; i < arr.size(); i++) {
        if (st.find(arr[i]) != st.end() || arr[i] == '$') continue;
        curr += arr[i];
        st.insert(arr[i]);
        char t = arr[i];
        arr[i] = '$';
        solve(idx + 1, curr, arr, res);
        arr[i] = t;
        curr.pop_back();
    }
}

int main() {

    vector<char>arr;
    vector<string>res;
    string temp;
    
    cin>>temp;

    for (char c: temp) arr.push_back(c);
    string curr = "";
    solve(0, curr, arr, res);

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto el: res) {
        cout << el << endl;
    }
    
return 0;
}
