/*
!    Return an array containing sum of all bit positions from 1 to n
!    
!    for example :-
!    0 0 0 0  0
!    0 0 0 1  1
!    0 0 1 0  2
!    0 0 1 1  3
!    0 1 0 0  4
!    0 1 0 1  5
!    0 1 1 0  6
!    0 1 1 1  7
!    1 0 0 0  8
!    1 0 0 1  9
!    1 0 1 0  10
!    1 0 1 1  11
!    1 1 0 0  12
!    1 1 0 1  13
!    1 1 1 0  14
!    1 1 1 1  15
!
!   [8,8,8,8] -> sum array 
!
!   tutorial : https://youtu.be/D5yhQ-bqw9E?si=5FPSIeZkDKYB4HSY  timestamp ~ 50:00
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>bitCount;
void getBitsCount(ll num){
    if(num == 0) return; //0
    if(num == 1){ // 0, 1
        bitCount[0] += 1;
        return;
    }
    if(num == 2){ //00, 01, 10
        bitCount[0] += 1;
        bitCount[1] += 1;
        return;
    }
    ll bitLen = log2(num)+1; 
    ll nearPower2 = pow(2, bitLen - 1);
    //or ll nearPower2 = (1ll << (bitLen-1));

    bitCount[bitLen - 1] += (num - nearPower2) + 1;

    for(ll i = 0; i < bitLen - 1; i++){
        bitCount[i] += nearPower2 / 2;
    }
    num -= nearPower2;
    getBitsCount(num);
}

int main()
{
    bitCount = vector<ll>(65, 0);
    int n;
    cin>>n;
    getBitsCount(n);
    for(auto el: bitCount){
        cout<<el<<" ";
    }

    return 0;
}

