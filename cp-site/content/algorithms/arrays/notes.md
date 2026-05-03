# Sorting:

## Bubble Sort:
```cpp
void bubblesort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

```

## Quick Sort: 
```cpp
int findPivot(vector<int>& arr, int s, int e) {
    int idx = s;
    int pivotEl = arr[e];
    for (int i = s; i < e; i++) {
        if (arr[i] < pivotEl) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[idx], arr[e]);

    return idx;
}

void quicksort(vector<int>& arr, int s, int e) {
    if (s >= e) return;

    int pIdx = findPivot(arr, s, e);

    quicksort(arr, s, pIdx - 1);
    quicksort(arr, pIdx + 1, e);
}
```

## Merge Sort: 
```cpp
void merge(vector<int>& arr, int s, int mid, int e) {
    vector<int>temp;
    int i = s, j = mid + 1;

    while (i <= mid and j <= e) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);;
    while (j <= e) temp.push_back(arr[j++]);

    int k = 0;

    for (int i = s; i <= e; i++) {
        arr[i] = temp[k++];
    }

}

void mergesort(vector<int>& arr, int s, int e) {
    if (s >= e) return;

    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
```

## Counting Sort:
```cpp
void countingSort(vector<int>& arr) {
    int n = arr.size();
    int maxEl = *max_element(arr.begin(), arr.end());

    vector<int> count(maxEl + 1, 0);
    
    for (int num : arr) {
        count[num]++;
    }

    // Cumulative sum
    for (int i = 1; i <= maxEl; i++) {
        count[i] += count[i - 1];
    }

    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {
        result[--count[arr[i]]] = arr[i];
    }

    arr = result; // Directly assign result to arr
}

```

## Insertion Sort:
```cpp
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        int j = i - 1;
        int k = i;
        while(j >= 0 and arr[j] > arr[k]) {
            swap(arr[j--], arr[k--]);
        }
    }
}
```

## Selection Sort: 
```cpp
void selectionSort(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        vector<int>::iterator it = min_element(arr.begin() + i, arr.end());
        swap(arr[i], *it);
    }

}
```

## Radix Sort:
```cpp
void digitsort(vector<int>&arr, int exp) {
    vector<vector<int>>count(10);

    for (int i = 0; i < arr.size(); i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit].push_back(arr[i]);
    }

    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (auto el: count[i]) {
            arr[k++] = el;
        }
    }

    
}

void radixsort(vector<int>& arr) {
    int maxx = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxx / exp > 0; exp *= 10) {
        digitsort(arr, exp);
    }
}
```