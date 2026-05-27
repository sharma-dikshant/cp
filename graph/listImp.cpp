#include <bits/stdc++.h>
using namespace std;

void print_graph(unordered_map<int, vector<int>> &graph)
{
    for (auto &node : graph)
    {
        cout << "Node " << node.first << " ";
        for (auto &n : node.second)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{

    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};

    // creating list
    unordered_map<int, vector<int>> graph;

    for (auto &edge : edgeList)
    {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    print_graph(graph);
    return 0;
}