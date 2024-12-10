#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k;
        int n, m;
        cin >> k;
        unordered_map<int, int> hash;
        for (int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            hash[temp]++;
        }
        int elements = k - 2;

        for (auto& el : hash)
        {
            int a = el.first;
            int b = elements / a;

            if (elements % a == 0 and hash.find(b) != hash.end())
            {
                if (a != b or (a == b and hash[a] > 1))
                {
                    m = a;
                    n = b;
                    break;
                }
            }
        }

        cout << m << " " << n << endl;
    }
    return 0;
}