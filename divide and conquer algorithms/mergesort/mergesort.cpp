#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;

    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // copying remaining element
    while (i <= m)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }

    // modifing the original arr
    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k++];
    }
    return;
}

void mergesort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return; // either one element or no element
    }

    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;

    mergesort(arr, s, e);

    for(auto n: arr){
        cout<<n<<" ";
    }

    return 0;
}