#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll start = 0;
    ll end = 10e9;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout<<mid<<endl;
        cout<<flush;

        int temp;
        cin >> temp;

        if (temp == 0)
        {
            cout << "found!" << endl;
            return 0;
        }

        if (temp == -1)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        cout<<flush;
    }
    return 0;
}