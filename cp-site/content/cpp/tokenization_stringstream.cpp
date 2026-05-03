#include <bits/stdc++.h>
using namespace std;

int main()
{
    //input the string
    string input = "token1/token2/token3/.//";
    //vector to store the tokens
    vector<string> tokens;

    //stringstream class for tokenization
    stringstream hello(input);

    //string to store current string token
    string currtoken;

    while(getline(hello, currtoken, '/')) {   //here / is called delimiter
        //push the current token
        tokens.push_back(currtoken);
    }

    //print the tokens
    for(auto el: tokens) {
        cout<<el<<endl;
    }


    return 0;
}