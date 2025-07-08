#include<bits/stdc++.h>
using namespace std;

//? single inheritance : 1 Parent -> 1 Child
class A { };
class B: public A { };

//? multilevel inheritance : 1 Parent -> 1 Sub-Child -> 1 child
class A1 { };
class B1: public A1 { };
class C2: public B1 { };

//? Multiple inheritance 2 Parent -> 1 child  can lead ambiguity
class A2 { };
class B2 { };

class C2: public A2, private B2 { };
//? Hybrid


int main() {


return 0;
}