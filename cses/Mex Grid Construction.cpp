#include <bits/stdc++.h>
using namespace std;

bool canPlace(int val, int i, int j, vector<vector<int>>& grid) {
    int x = i, y = j;
    // checking up in col
    while (x >= 0) {
        if (grid[x][j] == val) return false;
        x--;
    }

    // checking left in row
    while (y >= 0) {
        if (grid[i][y] == val) return false;
        y--;
    }

    return true;
}

bool solve(int i, int j, vector<vector<int>>& grid) {
    if (i == grid.size()) {
        return true;
    }

    if (j == grid.size()) {
        return solve(i + 1, 0, grid);
    }

    for (int val = 0; val <= grid.size() * grid.size(); val++) {
        if (canPlace(val, i, j, grid)) {
            grid[i][j] = val;
            if (solve(i, j + 1, grid)) {
                return true;
            }
        }
    }

    return true;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, -1));
    solve(0, 0, res);

    for (auto v: res) {
        for (auto el: v) {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}