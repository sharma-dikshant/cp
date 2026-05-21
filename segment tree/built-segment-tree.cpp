#include<iostream>
using namespace std;


void buildTree(int i, int l, int r, vector<int>& segTree, vector<int>& arr) {
    if (l == r) {
        segTree[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    buildTree(2 * i + 1, l, mid, segTree, arr);
    buildTree(2 * i + 2, mid + 1, r, segTree, arr);


    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];

    return;
}

int main() {

    vector<int>arr = {3, 1, 2, 7, 1};
    int n = arr.size();

    vector<int>segTree(2 * n);

    buildTree(0, 0, n - 1, segTree, arr);


    for (int el: segTree) cout << el << " ";

return 0;
}