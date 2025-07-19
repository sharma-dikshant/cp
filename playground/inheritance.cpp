#include<bits/stdc++.h>
using namespace std;

class A { };

class B: A {};  //? if access specifier is not mentioned then it is private by default

int main() {

    A* obj = new B();

return 0;
}