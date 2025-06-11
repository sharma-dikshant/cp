#include<bits/stdc++.h>
using namespace std;

int color[4] = {'A', 'B', 'C', 'D'};

bool canPlace(char el, int i, int j, vector<vector<char>>& grid) {
    if (i > 0 && grid[i - 1][j] == el) return false;
    if (j > 0 && grid[i][j - 1] == el) return false;
    return true;
}

bool solve(int i, int j, vector<vector<char>>& grid) {
    if (i == grid.size()) return true;
    if (j == grid[0].size()) return solve(i + 1, 0, grid);


    for (auto el: color) {
        if (el != grid[i][j] && canPlace(el, i, j, grid)) {
            char t = grid[i][j];
            grid[i][j] = el;
            if (solve(i, j + 1, grid)) return true;
            grid[i][j] = t;
        }
    }

    return false;
}

int main() {

    int n, m;
    cin>>n>>m;
    // n x m
    vector<vector<char>>grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string temp;
        cin>>temp;
        for (int j = 0; j < m; j++) {
            grid[i][j] = temp[j];
        }
    }

    if (solve(0, 0, grid)) {
        for (auto r: grid) {
            for (auto el: r) {
                cout << el;
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

return 0;
}