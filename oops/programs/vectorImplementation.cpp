#include<iostream>

class vector {
    public:
        int size;
        int capacity;
        int* arr;

        vector() {
            size = 0;
            capacity = 1;
            arr = new int[capacity];
        }

        vector(int size) {
            this->size = size;
            this->capacity = size;
            arr = new int[capacity];
        }

        void push_back(int el) {
            if (size == capacity) {
                capacity *= 2;
                int* new_arr = new int[capacity];
                for (int i = 0; i < size; i++) {
                    new_arr[i] = arr[i];
                }
                delete arr;
                arr = new_arr;
            }

            arr[size++] = el;
        }

        void pop_back() {
            size -= 1; 
        }
};

int main() {
    vector arr;
    for (int i = 0; i < 1000; i++) {
        arr.push_back(i);
    }
    // std::cout<<arr.size;
    std::cout<<arr.capacity;
}