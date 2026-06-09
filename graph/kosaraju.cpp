#include<iostream>
using namespace std;

void findFinishTimeOrder(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited, vector<int>& order) {
    visited[node] = true;

    for (int nbh: graph[node]) {
        if (!visited[nbh]) findFinishTimeOrder(nbh, graph, visited, order);
    }

    order.push_back(node);

    return;
}

void dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int nbh: graph[node]) {
    if (!visited[nbh]) dfs(nbh, graph, visited);
    }

    return;
}

int main() {

    int V = 5;
    vector<vector<int>>edges = {{0, 2}, {0, 3}, {1, 0}, {2, 1}, {3, 4}};

    unordered_map<int, vector<int>>actGraph, revGraph;
    vector<bool>visited(V, false);

    for (auto& ed: edges) {
        int u = ed[0],
            v = ed[1];

        actGraph[u].push_back(v);
        revGraph[v].push_back(u);
    }


    vector<int>order;
    
    // calculate finishTime order
    for (int i = 0; i < V; i++) {
        if (!visited[i]) findFinishTimeOrder(i, actGraph, visited, order);
    }

    reverse(order.begin(), order.end());

    fill(visited.begin(), visited.end(), false);

    for (int node: order) {
        // cout << node << endl;
        if (visited[node]) continue;
        dfs(node, revGraph, visited);
        cout << "------" << endl;
    }
    
    return 0;
}