#include<bits/stdc++.h>
using namespace std;    

void dfs(int node, unordered_map<int, vector<int>>& adjList, vector<int>& topoSort) {
    static unordered_set<int> visited;
    visited.insert(node);

    for (int neighbor : adjList[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, adjList, topoSort);
        }
    }

    topoSort.push_back(node);
}

int main() {

    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5}
    };

    unordered_map<int, vector<int>> adjList;
    for (auto edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
    }

    vector<int>topoSort;

    dfs(1, adjList, topoSort);

    reverse(topoSort.begin(), topoSort.end());
    cout << "Topological Sort: ";
    for (int node : topoSort) {
        cout << node << " ";
    }

    return 0;
}