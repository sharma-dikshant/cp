#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;
    int cnt = 0;
    while (i <= m and j <= e)
    {
        if (arr[i] > arr[j])
        {
            temp.push_back(arr[j++]);
            cnt += (m - i + 1);
        }
        else
        {
            temp.push_back(arr[i++]);
        }
    }

    while (i <= m)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k++];
    }
    return cnt;
}
int mergesort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return 0;

    int mid = (s + e) / 2;
    int c1 = mergesort(arr, s, mid);
    int c2 = mergesort(arr, mid + 1, e);
    int ci = merge(arr, s, e);

    return c1 + c2 + ci;
}
// Function to count inversions in the array.
int inversionCount(vector<int> &arr)
{
    // Your Code Here
    int result = 0;
    int s = 0;
    int e = arr.size() - 1;
    result = mergesort(arr, s, e);

    return result;
}

int main()
{
    vector<int>arr = {33,2,1,4,2,4,5,6};
    int result = inversionCount(arr);
    cout<<result<<endl;
    return 0;
}