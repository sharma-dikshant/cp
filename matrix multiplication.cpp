#include <bits/stdc++.h>
using namespace std;

void print(const vector<vector<int>>& mat) {
    for (auto& r : mat) {
        for (int el : r) cout << el << " ";
        cout << endl;
    }
}

vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int r1 = mat1.size(), c1 = mat1[0].size();
    int r2 = mat2.size(), c2 = mat2[0].size();

    // check if multiplication possible
    if (c1 != r2) {
        throw invalid_argument("Matrix dimensions do not allow multiplication");
    }

    vector<vector<int>> res(r1, vector<int>(c2, 0));

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}

int main() {
    int m1, n1, m2, n2;
    cout << "Enter dimension of first matrix (rows cols): ";
    cin >> m1 >> n1;
    cout << "Enter dimension of second matrix (rows cols): ";
    cin >> m2 >> n2;

    vector<vector<int>> mat1(m1, vector<int>(n1));
    vector<vector<int>> mat2(m2, vector<int>(n2));

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) cin >> mat1[i][j];
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) cin >> mat2[i][j];
    }

    try {
        vector<vector<int>> res = multiply(mat1, mat2);
        cout << "Resultant matrix:\n";
        print(res);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
