#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int score = 0;
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        for(int i = 0; i < n; i++){
            if(arr[i] == -1) continue;
            for(int j = i + 1; j < n; j++){
                if(arr[i] == arr[j]){
                    score++;
                    arr[i] = -1;
                    arr[j] = -1;
                    break;
                }
            }
        }
        cout<<score<<endl;
    }

return 0;
}