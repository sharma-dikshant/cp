/*
 * The program reads an integer from the user, processes its digits, and outputs
 * the reversed number. It handles both positive and negative integers, ensuring
 * that the sign of the number is preserved in the reversed result.
 * 
 * Example:
 * Input:  12345
 * Output: 54321
 * 
 * Input:  -9876
 * Output: -6789
 * 
 * This program is useful for understanding basic number manipulation techniques
 * and working with loops and arithmetic operations in C++.
 */

 #include<bits/stdc++.h>
 using namespace std;

 int revNum(int n) {
    vector<int>arr;

    while (n) {
        arr.push_back(n % 10);
        n /= 10;
    }

    int t = 0, carry = 0;

    for (auto el: arr) {    
       t = t*10 + el;
    }

    return t;
 }
 
 int main() {
 
    int n;
    cin>>n;

    bool isNeg = false;
    if (n < 0) {
        isNeg = true;
        n *= -1;
    }

    string s = to_string(n);
    reverse(s.begin(), s.end());

    int f1 = stoi(s);
    int f2 = revNum(n);
    if (isNeg) {
        f1 *= -1;
        f2 *= -1;
    }

    cout << f1 << endl;
    cout << f2 << endl;
 
 return 0;
 }