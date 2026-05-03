#include<iostream>
using namespace std;

const int INF = 1e8;

void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int V = dist.size();
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // go i->j via k
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    return;
}

int main() {
    return 0;
}