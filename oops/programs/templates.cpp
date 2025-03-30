#include <bits/stdc++.h>
using namespace std;

template <class Type>
Type add (Type a, Type b) {
    return a + b;
}

int main() {
    int some_int_res = add<int>(3, 54);
    float some_float_res = add<float>(3.0, 54.22);

    cout<<some_int_res<<" "<<some_float_res;
    return 0;
}