# Algorithms:  

## 🔥 Popular Patterns:  
- Sliding Window
- Two Pointers
- Fast and Slow Pointers
- Prefix Sum
- Difference Array

## 1. Strings  
- ### Pattern Matching  
    - [Naive Pattern Matching (or by using find() function)](./algorithms/strings/kmp.cpp)
    - [KMP Algorithm](./algorithms/strings/kmp.cpp)
    - Rabin Karp Algorithm

## 2. Arrays
- ### Searching
    - Linear Search
    - Binary Search

- ### Sorting  
    - Bubble Sort
    - Selection Sort
    - Insertion Sort
    - Merge Sort
    - Quick Sort
    - Heap Sort
    - Counting Sort
    - Radix Sort
    - Bucket Sort

## 3. Trees
- ### Traversal
    - Inorder (recursive)
    - Preorder (recursive)
    - Postorder (recursive)
    - Level Order (BFS using Queue)
    - Inorder (iterative) : using stack
    - Inorder (iterative) : Morris Traversal (O(1) space) 



# Other Miscellaneous Concepts  

- **Shifting Alphabets**   
```cpp
    /* 
    Problem: 
    We've given a character and a number. We need to shift the character by that number:
    - If the number is positive, shift the character to the right.
    - If the number is negative, shift the character to the left.

    Examples:
        char = 'a', shift = 2 => output = 'c'
        char = 'z', shift = 3 => output = 'c'
        char = 'a', shift = -2 => output = 'y'
*/

/*
    Intuition: 
    Think of the alphabet as a circular array with indices ranging from 0 to 25. Shifting a character 
    corresponds to moving its index within this array, wrapping around as necessary. The key formulas are:
    
    1. For positive shifts: (current_index + shift) % n
    2. For negative shifts: (current_index + shift + n) % n 
       (where n = 26, the size of the alphabet array)

    Steps:
    1. Reduce large positive or negative shifts to the range of 0 to 25:
       shift = shift % 26

    2. Map the character to its array index (0-25):
       index = char - 'a'

    3. To get the character corresponding to a given index:
       char = index + 'a'

    4. For positive shifts:
       new_char = 'a' + (index + shift) % 26

    5. For negative shifts:
       new_char = 'a' + (index + shift + 26) % 26
*/

// Example implementation in C or C++:
#include <stdio.h>

char shiftCharacter(char c, int shift) {
    // Step 1: Normalize shift to range 0-25
    shift = shift % 26;

    // Step 2: Calculate new character based on shift
    if (shift >= 0) {
        return 'a' + (c - 'a' + shift) % 26;
    } else {
        return 'a' + (c - 'a' + shift + 26) % 26;
    }
}

int main() {
    // Test cases
    printf("%c\n", shiftCharacter('a', 2));  // Output: c
    printf("%c\n", shiftCharacter('z', 3));  // Output: c
    printf("%c\n", shiftCharacter('a', -2)); // Output: y

    return 0;
}


```
 