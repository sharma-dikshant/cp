#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> &adj)
{
    for (int i = 1; i < adj.size(); i++)
    {
        cout << "Node " << i << "->" << " ";
        for (int j = 1; j < adj[0].size(); j++)
        {
            if (adj[i][j])
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return;
}

int main()
{

    // graph implementation using adjacency matrix
    // edge list
    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};

    int n = edgeList.size();

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (auto &edge : edgeList)
    {
        int first = edge[0];
        int second = edge[1];
        adj[first][second] = 1;
        adj[second][first] = 1; // for undirected graph either one of these condition is used
    }

    print_graph(adj);

    return 0;
}