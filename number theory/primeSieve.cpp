#include<bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long
void primeSieve(vector<int>& sieve){
    //Mark 0 and 1 as not prime
    sieve[0] = sieve[1] = 0;

    //start from 2 and mark all multiples of ith(prime) as not prime

    for(ll i = 2; i <=N; i++){
        if(sieve[i]){
            for(ll j = i*i; j <=N; j = j+i){
                //marking as not prime
                sieve[j] = 0;
            }
        }
    }
}

int main()
{
vector<int>sieve(N, 1); 

    primeSieve(sieve);

    for(int i = 0; i <= 100; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }

return 0;
}