#include<iostream>
using namespace std;

int findParent(int node, vector<int>& parents) {
    if (parents[node] == node) return node;
    return parents[node] = findParent(parents[node], parents);  // update the parent after recursion finds the parent
}

int unionNodes(int x, int y, vector<int>& parents) {
    int parent_x = findParent(x, parents),
        parent_y = findParent(y, parents);

    if (parent_x == parent_y) return parent_x;

    parents[parent_y] = parent_x;
    return parent_x;
}

int main() {


return 0;
}