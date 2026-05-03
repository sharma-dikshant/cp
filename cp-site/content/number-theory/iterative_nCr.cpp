#include<iostream>
using namespace std;

int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 1) return n;
    if (r == 0) return 1;

    r = min(r, n - r);
    
    long long res = 1;

    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
        
}

int main() {


    cout << nCr(10, 5) << endl;

return 0;
}