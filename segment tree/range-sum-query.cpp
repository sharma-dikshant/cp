#include<iostream>
#include<vector>
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
}

int query(int ql, int qr, int idx, int l, int r, vector<int>& segTree) {

    // No overlap
    if (r < ql || l > qr)
        return 0;

    // Complete overlap
    if (ql <= l && r <= qr)
        return segTree[idx];

    // Partial overlap
    int mid = (l + r) / 2;

    return query(ql, qr, 2 * idx + 1, l, mid, segTree) +
           query(ql, qr, 2 * idx + 2, mid + 1, r, segTree);
}

int main() {

    vector<int> arr = {1,3,2,4,5,67,5,4};

    int n = arr.size();

    vector<int> segTree(4 * n);

    buildTree(0, 0, n - 1, segTree, arr);

    int sum = query(3, 4, 0, 0, n - 1, segTree);

    cout << sum << endl;

    return 0;
}