#include <bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int, int>>> &adj, vector<int> &visit, vector<vector<int>> &mst)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, -1}); //{wt, node, parent}

    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int node = it[1];
        int wt = it[0];
        int parent = it[2];

        if (visit[node])
            continue;
        visit[node] = 1;

        if (parent != -1)
        {
            mst.push_back({parent, node, wt});
        }
        sum += wt;

        // now inserting all the non visited neighbours of current neighbour
        for (auto &nbr : adj[node])
        {
            int nb = nbr.first;
            int wt = nbr.second;
            int par = node;

            if (!visit[nb])
            {
                pq.push({wt, nb, par});
            }
        }
    }

    return sum;
}

int main()
{

    int V = 3; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // visited arr
    vector<int> visit(V, 0);

    vector<vector<int>> mst;

    // Edge list: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}};

    // creating adjacency matrix
    for (auto e : edges)
    {
        int start = e[0];
        int end = e[1];
        int wt = e[2];

        adj[start].push_back({end, wt});
        adj[end].push_back({start, wt});
    }

    cout<<prims(adj, visit, mst)<<endl;

    for(auto ed: mst){
        cout<<ed[0]<<"->"<<ed[1]<<"--"<<ed[2]<<endl;
    }

    return 0;
}