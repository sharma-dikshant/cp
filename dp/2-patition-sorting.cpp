#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();

    vector<int>lis;  

    for (int i = 0; i < n; i++) {
        if (lis.empty()) {
            lis.push_back(arr[i]);
            continue;
        }

        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
            lis.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }

    cout << "LIS Size :" << lis.size() << endl;
    for (int i: lis) cout << i << " ";


    return 0;
}