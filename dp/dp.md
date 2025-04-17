# Dynamic Programming
- __Fibonacci sequence__
- __Longest Increasing Subsequence (LIS)__
- __Longest Common Subsequence (LCS)__
- __Longest Palindromic Subsequence (LPS)__
- __0/1 Knapsack Problem__
    - subset sum problem
    - equal sum partition problem
    - count of subsets with a given sum
    - minimum subset sum difference
    - target sum problem



## 0/1 knapsack   
### How to identify a 0/1 knapsack problem?
- Do you have a set of discrete items?
```txt
 -> you're given n things (tasks, projects, cakes, etc)
 -> you can't take half of any one item - either you take it or you leave it i.e. binary choice
```
- Each item has two attributes:
```txt
e.g. you've 5 tasks, each task takes some hours, and yields some benefit
```
- There's a single capacity/budget constraint
```txt
e.g. you can only work for 8 hours, or you have a budget of $1000
```
- Our goal is to maximize total value under that limit
- order of picking doesn't matter

### When it isn't a 0/1 knapsack problem?
- If you can take fractions of an item, it's a fractional knapsack problem (greedy approach)
- If you can take multiple copies of an item, it's a unbounded knapsack problem 
- sequence matters (e.g. job scheduling problems) - you can't pick a task before its dependencies are done

 