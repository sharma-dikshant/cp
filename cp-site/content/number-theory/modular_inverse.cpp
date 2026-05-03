#include<iostream>
using namespace std;

int modInverse(int a, int M) {
    int p = M - 2;
    int res = 1;

    while (p) {
        if (p & 1) {
            res = ((res % M) * (a % M)) % M;
        }

        a = ((a % M) * (a % M)) % M;

        p >>= 1;
    }

    return res % M;
}

int main() {



return 0;
}