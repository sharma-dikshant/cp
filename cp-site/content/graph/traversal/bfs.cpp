#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, vector<int> &visited)
{
    int root = 0;

    queue<int> q;
    q.push(root);
    visited[root] = 1; // mark 0 as visited

    while (!q.empty())
    {
        int temp = q.front();
        // removing and printing the first element
        cout << q.front() << " ";
        q.pop();

        for (auto &nbr : graph[temp])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }

    return;
}

int main()
{

    vector<vector<int>> edges = {{0, 3}, {0, 1}, {1, 2}, {2, 3}, {3, 7}, {3, 6}};
    unordered_map<int, vector<int>> graph;

    // making adjacency list
    for (auto ed : edges)
    {
        int a = ed[0];
        int b = ed[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(8, 0);
    bfs(graph, visited);

    return 0;
}