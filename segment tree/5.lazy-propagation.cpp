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


void rangeUpdate(int start, int end, int val, int idx, int left, int right, vector<int>& segTree, vector<int>& lazy) {
    // apply any existing update
    if (lazy[idx] != 0) {
        segTree[idx] += (right - left + 1) * lazy[idx];
        if (left != right) {
            lazy[2*idx + 1] += lazy[idx];
            lazy[2*idx + 2] += lazy[idx];
        } 

        lazy[idx] = 0;
    }

    // no overlapping
    if (end < left || right > start) {
        return;
    }

    // complete overlapping
    if (start >= left && end <= right) {
        segTree[idx] += (right - left + 1) * val;
        if (left != right) {
            lazy[2*idx + 1] += lazy[idx];
            lazy[2*idx + 2] += lazy[idx];
        } 
        return;
    }

    int mid = (left + right) / 2;
    rangeUpdate(start, end, val, 2*idx + 1, left, mid, segTree, lazy);
    rangeUpdate(start, end, val, 2*idx + 2, mid + 1, right, segTree, lazy);

    segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];

    return;
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