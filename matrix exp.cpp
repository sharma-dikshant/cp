#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix multiple(Matrix& mat1, Matrix& mat2) {
    int r1 = mat1.size(), c1 = mat1[0].size();
    int r2 = mat2.size(), c2 = mat2[0].size();

    // r1Xc1 r2Xc2 => r1Xc2
    if (c1 != r2) {
        cout << "INVALID DIMENSIONS!" << endl;
        return {{}};
    }

    Matrix res(r1, vector<int>(c2));

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int val = 0;
            for (int k = 0; k < c1; k++) {
                val += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = val;
        }
    }

    return res;
}

Matrix make_identity(int size) {
    Matrix mat(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) mat[i][i] = 1;
    return mat;
}

Matrix matrix_exp(Matrix& mat, int exp) {
    if (exp == 0) return make_identity(mat.size());
    if (exp == 1) return mat;

    Matrix half = matrix_exp(mat, exp / 2);
    Matrix res = multiple(half, half);

    if (exp & 1) res = multiple(res, mat);
    
    return res;
}

int main() {


    int n; 
    cout << "Enter n to compute nth Fibonacci number: ";
    cin>>n;

    Matrix T = {{1, 1}, {1, 0}};

    if (n == 0) {
        cout << "F(0) = 0" << endl;
    } else {
        Matrix result = matrix_exp(T, n - 1);
        cout << "F(" << n << ") = " << result[0][0] << endl;
    }


return 0;
}