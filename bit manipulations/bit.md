# GENERAL  
- __Fact 1__:  
Writing Lambda function in C++  
```cpp
    //this function should be written inside the function in which you use it.
    auto lambda = [] (int& a, int& b){
        return a+b;
    };
```
# BIT MANIPULATION
- __Fact 1__:  
To get right most bit of any number, we can use `n & 1`.  
`
    0100  (4)  & 0001  (1) = 0000
`  
So the rightmost bit of 1 is 0.

    ______

- __Fact 2__:  
TO count no. of set bits in n
`
__builtin_popcount(n)
`
    
     ______

- __Fact 3__:  
To check if a number is power of 2 or not, we can use `n & (n-1)`.  
`
    0100  (4)  & 0011  (3) = 0000
`  
Also to unset the rightmost set bit of an intger  

```cpp
    n = n & (n-1)  
    //for example
    n     = 110010 - 50
    n-1   = 110001 - 49
    n&n-1 = 110000 - 48
    //therefor the 2nd bit of 50 become unset
```
    
______

- __Fact 4__:  
In any number there are `log(n)` bits.

______

- __Fact 5__:  
`a*pow(2,b) = a<<b`
________

- __Fact 6__:  
to represent any number in binary we required `log(n)+1` bits.
________
- __Fact 7__:  
For a number `pow(2, n)` we require atleast `n+1` bits.  
Also `pow(2, n)` is equal to `1<<n`.
