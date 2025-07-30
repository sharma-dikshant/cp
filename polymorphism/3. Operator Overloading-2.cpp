#include <iostream>
using namespace std;

struct Counter {
    int value;
};

Counter& operator++(Counter& c) {
    ++c.value;
    return c;
}

int main() {
    Counter c = {10};
    ++c;
    cout << "Counter: " << c.value << endl;  // Output: 11
}
