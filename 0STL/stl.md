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