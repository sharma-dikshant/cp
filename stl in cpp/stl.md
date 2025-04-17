# Comparator:

- It is a function or an object that is used to compare elements.
- Used to decide order of the elements in data structures.
- **3 Ways to implement Comparators** :
  1. **Function Pointer**
  2. **Function Object**
  3. **Lambda Function**

## Function Pointer:

example - 1:

```cpp
bool comp(int a, int b) {
    return a > b;
}

int main() {
    vector<int>arr = {1,3,53,5,3,2,5,2,5,55,3,6,43,5,3};
    sort(begin(arr), end(arr), comp);
}

```

example - 2:

```cpp

// comparator function to sort pairs on the basis of second element in decreasing order and of second elements are same then sort on the basis of first element in increasing order
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        return true;
    }
    return false;
}

/*
    bool comp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == a.second) {
            return a.first < b.first;
        }

        return a.second < b.second;
    }
*/

int main () {
vector<pair<int, int>> arr = {
        {1, 2},
        {343, 2},
        {44, 1},
        {6, 4},
        {0, 44},
        {2, 54}};
    sort(begin(arr), end(arr), comp);
}
```

## Functors (Function Object):

By using function objects and operator overloading, we can store the state of the comparator.

```cpp
class myComparator
{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == a.second)
        {
            return a.first < b.first;
        }

        return a.second < b.second;
    }
};

int main() {
    vector<pair<int, int>> arr = {
        {1, 2},
        {343, 2},
        {44, 1},
        {6, 4},
        {0, 44},
        {2, 54}};
    sort(begin(arr), end(arr), myComparator());
}
```

## Lambda Function:

```cpp
vector<pair<int, int>> arr = {
        {1, 2},
        {343, 2},
        {44, 1},
        {6, 4},
        {0, 44},
        {2, 54}};
    // sort(begin(arr), end(arr), comp);
    sort(begin(arr), end(arr), [](pair<int, int> a, pair<int, int> b) -> bool
         {
        if (a.first == a.second)
        {
            return a.first < b.first;
        }

        return a.second < b.second; });
```

lambda expression is a function without a name. It is used to create an anonymous function. It is a feature of C++11.

general lambda syntax:

```cpp
[capture clause](parameters) -> return-type
{
    definition of method
}
```

- **Capture clause** : It is used to capture variables from the surrounding scope.
- **Parameters** : It is the list of parameters that the lambda function will take.


# STL Algorithms:

- **STL** : Standard Template Library
- **STL Algorithms** : Algorithms that are used to perform operations on data structures.
- **STL Algorithms** are used to perform operations on data structures like searching, sorting, counting, manipulating, etc.
- **STL Algorithms** are present in the `<algorithm>` header file.  

## Types of STL Algorithms:

1. **Non-modifying Algorithms** : These algorithms do not modify the data structure.
2. **Modifying Algorithms** : These algorithms modify the data structure.
3. **Sorting Algorithms** : These algorithms are used to sort the data structure.
4. **Numeric Algorithms** : These algorithms are used to perform numeric operations.

## Non-modifying Algorithms:

1. **all_of()** : It checks if all the elements in the range satisfy the given condition.
2. **any_of()** : It checks if any of the elements in the range satisfy the given condition.
3. **none_of()** : It checks if none of the elements in the range satisfy the given condition.
4. **for_each()** : It applies a function to each element in the range.
5. **count()** : It counts the number of elements in the range that satisfy the given condition.
7. **mismatch()** : It finds the first mismatch between two ranges.
8. **equal()** : It checks if two ranges are equal.
9. **is_permutation()** : It checks if a range is a permutation of another range.
10. **find()** : It finds the first occurrence of an element in the range.
11. **find_if()** : It finds the first element in the range that satisfies the given condition.


## Modifying Algorithms:

1. **copy()** : It copies the elements from one range to another.
7. **swap()** : It swaps the elements of two ranges.

10. **transform()** : It applies a function to each element in the range and stores the result in another range.



25. **reverse()** : It reverses the elements in the range.
27. **rotate()** : It rotates the elements in the range.

## Sorting Algorithms:

1. **sort()** : It sorts the elements in the range.
2. **upper_bound()** : It finds the first element in the range that is greater than the given value.
```txt
    return el > given value
```
3. **lower_bound()** : It finds the first element in the range that is greater than or equal to given value.
```txt
    return el >= given value
```

## Numeric Algorithms:

1. **accumulate()** : It calculates the sum of the elements in the range.
2. **inner_product()** : It calculates the inner product of two ranges.
3. **adjacent_difference()** : It calculates the difference between adjacent elements in the range.
4. **partial_sum()** : It calculates the partial sum of the elements in the range.
