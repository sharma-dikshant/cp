#include<bits/stdc++.h>
using namespace std;

void update(int arr[]) {
    arr[0] += 1;
}

int main() {

    int arr[10] = {0};

    for (int x: arr) cout << x << endl;
    update(arr);
    for (int x: arr) cout << x << endl;


return 0;
}