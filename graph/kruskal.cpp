#include <iostream>
using namespace std;


int findParent(int node, vector<int>& parents) {
    if (node == parents[node]) return node;
    return parents[node] = findParent(parents[node], parents);
}

bool isDisjoint(int u, int v, vector<int>& parents) {
    int u_parent = findParent(u, parents);
    int v_parent = findParent(v, parents);

    return u_parent != v_parent;
}

int unionNodes(int u, int v, vector<int>& parents) {
    int u_parent = findParent(u, parents);
    int v_parent = findParent(v, parents);

    if (u_parent == v_parent) return u_parent;

    parents[v_parent] = u_parent;
    return u_parent;
}

int kruskal(int V, vector<vector<int>>& edges) {
    int sum = 0;

    vector<int>parents(V);
    for (int i = 0; i < V; i++) parents[i] = i;


    for (auto& e: edges) {
        int u = e[0],
            v = e[1],
            w = e[2];

        if (!isDisjoint(u, v, parents)) continue; // already included

        sum += w;
        unionNodes(u, v, parents);
    }

    return sum;
}

int main() {

    int V = 3; // Number of vertices

    // Edge list: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}};

    sort(edges.begin(), edges.end(), [&](auto& a, auto& b) {
        return a[2] < b[2];
    });


    cout << kruskal(V, edges) << endl;

    return 0;
}