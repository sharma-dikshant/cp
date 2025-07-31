/*
basically circular queue is similar to regular queue, however it distinguishes itself
by connecting the last position back to first;

overcoming the storage wastage in linear queue

also based on FIFO
*/


#include<bits/stdc++.h>
using namespace std;

class Queue {
    private:
        int* arr;
        int f_ptr, size, capacity;
    public:
        Queue(int c) {
            arr = new int[c];
            capacity = c;
            f_ptr = 0;
            size = 0;
        }

        int front() {
            if (size == 0) return -1;
            return arr[f_ptr];
        }

        int back() {
            if (size == 0) return -1;
            return arr[(f_ptr + size - 1) % capacity];
        }

        void push(int val) {
            if (size == capacity) return;
            arr[(f_ptr + size) % capacity] = val;
            size += 1;
        }

        void pop() {
            if (size == 0) return;
            f_ptr = (f_ptr + 1) % capacity;
            size -= 1;
        }

        bool empty() {
            return size == 0;
        }
};

int main() {

    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.push(6);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

return 0;
}