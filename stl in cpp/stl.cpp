# include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int>arr = {1,2,3,4,5,6,7};
    cout << std::binary_search(arr.begin(), arr.end(), 5) << endl;

    vector<int>arr1 = {1,2,3, 4, 5,6, 4,4,4,4,4, 7};

    int total = 0;
   do {
    total += 1;
   } while (std::next_permutation(arr.begin(), arr.end()));
   
//    cout << "Total Permulation: " << total << endl;

   cout << gcd(2, 4) << endl;

    return 0;
}