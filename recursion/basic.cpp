#include <bits/stdc++.h>
using namespace std;

void printOneToN(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    printOneToN(i + 1, n);
}
void printNToOne(int i, int n)
{
    if(i > n)
        return;
    
    printNToOne(i+1, n);
    cout<<i<<" ";
}

int main()
{

    int n;
    cin >> n;
    printOneToN(1, n);
    cout << endl;
    printNToOne(1, n);
    return 0;
}