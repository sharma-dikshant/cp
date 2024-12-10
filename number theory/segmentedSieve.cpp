#include<iostream>
#include<vector>
using namespace std;
#define N 100000
#define ll long long

int sieveArr[N+1] = {0};
vector<int>primes;

void sieve(){
    for(ll i = 2; i<=N; i++){
        if(sieveArr[i] == 0){
            primes.push_back(i);
            //mark the multiples of i as non-primes
            for(ll j = i*i; j <=N; j+=i){
                sieveArr[j] = 1; //not prime
            }
        }
    }
}

int main()
{




return 0;
}