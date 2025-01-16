# Number Theory:  
__Topics__:  
- [Factors of a Number.](#factors-of-a-number)  
- [Prime Number.](#prime-number)  
- [Sieve of Eratosthenes.](#sieve-of-eratosthenes)  
- [Prime Factorization.](#prime-factorization)
- Binary and Modular Exponentiation.
- Modular Arithmetic.  
- LCM and GCD.  
- Factorial and nCr.  

# Factors of a Number:  
 __Brute Force Method__: Iterate from 1 to n and check if n is divisible by i.
 ```cpp
 void factors(int n) {

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }
 }

 // complexity: O(n)
 ```

__Optimized Method__: Iterate from 1 to sqrt(n) and check if n is divisible by i and n/i.  
- __Reason__: 

```txt
     Let the number be N.
     we know N = sqrt(N) * sqrt(N).
     write it as N = a * b.
        now, if a < sqrt(N) then, for sure b > sqrt(N).
        so, we can find all the factors of N by iterating from 1 to sqrt(N).
        therefore, for each i from 1 to sqrt(N), we can find two factors i and N/i.
```

```cpp
void findFactor(int n) {
    for (int i = 1; i * i <= n>; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}

// complexity: O(sqrt(n))
```

# Prime Number:  
__Brute Force Method O(n)__: Check if a number is prime or not by iterating from 2 to n-1.  


__Better Method O(sqrt(n))__: We've already seen that we can find all the factors of a number by iterating from 1 to sqrt(n). So, checking if a number is prime or not can be done by iterating from 2 to sqrt(n).

```cpp
bool checkPrime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
```

# Sieve of Eratosthenes:  
__Problem__: Find all the prime numbers in 1 to n.  
__Brute Force Method__: Check if a number is prime or not by iterating from 2 to n-1.  
```cpp
void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            cout << i << " ";
            for(int j = 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// complexity: O(n * sqrt(n))
```

__Better Method__: Check if a number is prime or not by iterating from 2 to sqrt(n).  
```cpp
 void sieve(int n) {
   vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            for(int j = 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
 }

    // complexity: O(n * log(log(n)))
```

__More Optimized Method__:  The inner loop should be starts with `i*i` instead of `2` because all the numbers before `i*i` are already marked as false by the smaller prime numbers.  
```cpp
void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// complexity: O(n * log(log(n)))
```

# Prime Factorization:  
__Problem__: Find all the prime factors of a number.  
__O(n) solution__:
```cpp
void primeFactorize(int n) {
    if(n <= 1) return;

    for(int i = 2; i <= n; i++) {
        if(n % 2 == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            cout << i << "^" << cnt << " ";
        }
    }
}
```

__O(sqrt(n)) solution__:
```cpp
void primeFactorize(int n) {
    if(n <= 1)  return;

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                cnt++;
                n /= i;
            }
            cout<< i << "^" << cnt<<" ";
        }
    }
}
```