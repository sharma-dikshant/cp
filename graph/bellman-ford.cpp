#include <iostream>
using namespace std;

const int INF = 1e8;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int>distance(V, INF);
    distance[src] = 0;
    
    for (int i = 1; i <= V - 1; i++) {
        for (auto e: edges) {
            int a = e[0],
                b = e[1],
                w = e[2];
                
            if (distance[a] != INF && distance[b] > distance[a] + w)
                distance[b] = min(distance[b], distance[a] + w);
        }
    }
    
    
    // checking for negative cycle
    for (auto e: edges) {
            int a = e[0],
                b = e[1],
                w = e[2];
                
            if (distance[a] != INF && distance[b] > distance[a] + w) {
                int t = min(distance[b], distance[a] + w);
                if (t < distance[b]) return { -1 };
            }
        }
    
    return distance;
}

int main() {
    return 0;
}