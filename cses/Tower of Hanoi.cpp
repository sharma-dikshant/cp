#include<bits/stdc++.h>
using namespace std;

void solve(int n, int src, int from, int dist) {
    if (n == 0) return;
    // moving n -1 from src to from using dist
    solve(n - 1, src, dist, from);
    cout << src << " " << dist << endl;
    solve(n - 1, from, src, dist);
}

int main() {

    int n;
    cin>>n;
    // total 2^n - 1 moves
    int t_moves = (1 << n) - 1;
    cout << t_moves << endl;
    solve(n, 1, 2, 3);

return 0;
}