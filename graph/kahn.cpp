
/**
 * Kahn's Algorithm for Topological Sorting
 * This implementation uses Kahn's algorithm to perform topological sorting on a directed acyclic graph (DAG).
 * The algorithm works by maintaining a list of nodes with no incoming edges (indegree of 0) and repeatedly removing them from the graph while updating the indegree of their neighbors. 
 * The process continues until all nodes are processed or a cycle is detected (if there are still nodes with non-zero indegree).
 */

#include<bits/stdc++.h>
using namespace std;

int main () {
    
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 1},
        {3, 4},
        {4, 5}
    };

    int n = 5; // Number of nodes in the graph
    unordered_map<int, vector<int>> adjList;
    vector<int> indegree(6, 0); // Assuming nodes are labeled from 1 to 5

    for (auto edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 1; i <= 5; i++) {
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

    if (topoSort.size() != n) {
        cout << "Cycle detected in the graph. Topological sort not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int node : topoSort) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}