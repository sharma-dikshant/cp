#include<bits/stdc++.h>
using namespace std;    

int main() {

    vector<vector<int>>edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}};
    int n = 5; // number of nodes
    unordered_map<int, vector<int>> adjList;
    vector<int>indegree(n, 0);


    for (auto edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
    }

    for (auto edge : edges) {
        indegree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoSort;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topoSort.push_back(node);

        for (int neighbor : adjList[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    cout << "Topological Sort: ";
    for (int node : topoSort) {
        cout << node << " ";
    }

    return 0;
}