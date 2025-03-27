# Josephus Problem  
## Problem Statement  
![Josephus Problem](./josephus.gif)

**The problem** — given the number of people, starting point, direction, and number to be skipped — is to choose the position in the initial circle to avoid execution.

[Numberphile link](https://youtu.be/uCsD3ZGzMgE?si=f2l9k53pa-9Td6XT)  
## Solution
The problem can be solved using a recursive function. The function `josephus(n, k)` takes two arguments: `n` is the number of people in the circle, and `k` is the number of people to be skipped. The function returns the position of the person who survives.

**Recursive function**
```text
f(n,k)=((f(n−1,k)+k−1)modn)+1   // 1-based indexing
f(n,k)=((f(n−1,k)+k−1)modn)     // 0-based indexing

Base Case:
f(1,k)=0 // 0-based indexing
i.e. when there is only one person in the circle, he will survive.

```

```cpp
int josephus(int n, int k) {
    if (n == 1) return 0;
    return (josephus(n - 1, k) + k) % n;
}
```