#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pi = s;
    int pivot = arr[e];

    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pi]);
            pi++;
        }
    }

    // final swap for pivot element
    swap(arr[e], arr[pi]);

    return pi;
}

void quicksort(vector<int> &arr, int s, int e)
{
    if (s > e)
        return;

    int pivot = partition(arr, s, e);
    quicksort(arr, s, pivot - 1);
    quicksort(arr, pivot + 1, e);
}

int main()
{
    vector<int> arr = {1, 33, 5, 6, 4, 4};
    quicksort(arr, 0, arr.size() - 1);

    for (auto el : arr)
    {
        cout << el << " ";
    }

    return 0;
}