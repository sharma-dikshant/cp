#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> input = {-1, 4, 32, 5, 4, 5, -5, -2};

    multiset<int, greater<int>> left; // Max-heap (stores smaller half)
    multiset<int> right;              // Min-heap (stores larger half)

    for (int el : input) {
        // Insert into correct heap
        if (left.empty() || el <= *left.begin()) {
            left.insert(el);
        } else {
            right.insert(el);
        }

        // Balance the two heaps
        if (left.size() > right.size() + 1) {
            right.insert(*left.begin());
            left.erase(left.begin());
        } else if (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    sort(input.begin(), input.end());
    cout<<input[input.size() / 2]<<endl;
    cout<<*left.begin();

    return 0;
}