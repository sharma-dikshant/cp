#include<bits/stdc++.h>
using namespace std;

bool canPlace(int r, int c, vector<vector<char>>& grid) {
    // check top
    int i = r, j = c;
    while (i >= 0) {
        if (grid[i][j] == 'q') return false;
        i--;
    }
    i = r;
    // check top-left
    while (i >= 0 && j >= 0) {
        if (grid[i][j] == 'q') return false;
        i--; j--;
    }
    i = r, j = c;
    while (i >= 0 && j < grid.size()) {
        if (grid[i][j] == 'q') return false;
        i--; j++;
    }

    return true;
}

int solve(int row, vector<vector<char>>& grid) {
    if (row == 8) {
        return 1;
    }

    int res = 0;
    for (int i = 0; i < 8; i++) {
        if (grid[row][i] != '*' && canPlace(row, i, grid)) {
            grid[row][i] = 'q';
            res += solve(row + 1, grid);
            grid[row][i] = '.';
        }
    }

    return res;
}

int main() {

    int n = 8;
    vector<vector<char>>grid(8, vector<char>(8));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }
    
    cout << solve(0, grid);



return 0;
}