#include<iostream>
using namespace std;

// #define VECTOR vector<pair<int, int>>
typedef vector<pair<int, int>> VECTOR;
const int INF = 1e9;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here
    unordered_map<int, VECTOR>adj;  // weight, node
    priority_queue<pair<int, int>, VECTOR, greater<pair<int, int>>>q;
    
    vector<int>distance(V, INF);
    distance[src] = 0;
    
    // prepare adjacency list
    for (auto e: edges) {
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }
    
    q.push({0, src});
    
    while (!q.empty()) {
        auto curr = q.top(); q.pop();
        
        int a = curr.second;
        
        for (auto u: adj[a]) {
            int b = u.second, w = u.first;
            
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({distance[b], b});
            }
        }
    }
    
    return distance;

}

int main() {
    return 0;
}