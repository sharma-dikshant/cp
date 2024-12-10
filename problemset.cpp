#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        arr[i].push_back(a);
        arr[i].push_back(b);
    }

    sort(arr.begin(), arr.end());
    for(auto el: arr){
        auto cur = el;
        cout<<cur[0]<<" "<<cur[1]<<endl;
    }

    return 0;
}
