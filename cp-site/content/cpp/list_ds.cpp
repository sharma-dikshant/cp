#include<bits/stdc++.h>
using namespace std;

void print(list<int>& l1) {
    for (auto el: l1) cout << el << endl;
}

int main() {


    list<int>l1 = {1,3,2,4,3,5,7,4,6,7,4,3};  //* list is doubly linked list
    list<int>l2(4, 19);  // (size, val)


    // print(l1);
    // print(l2);
    
                                                /**
                                                 ** Sort a list
                                                 */
    // ascending
    l1.sort();
    // print(l1);

    l1.sort([](int a, int b) {
        return a > b;
    });
    
    // print(l1);
    

    // inserting at front and back
    l1.push_back(13);
    l1.push_front(11);

    // deleting at front and back
    l1.pop_back();
    l1.pop_front();

    auto it = l1.begin();
    cout << *it << endl;
    advance(it, 2); //* move it by 2 element forward
    advance(it, -2); //* move it by 2 element reverse
    cout << *it << endl;

    //* insert at it position
    l1.insert(it, 23);

    //* delete at it position
    l1.erase(it); 


                                    /**
                                     * * Accessing Elements
                                     */

    // front
    l1.front();
    // back
    l1.back();


    //* updating only works with iterator
    *it = 343;
    // print(l1);


    //* reversing list 
    l1.reverse();

    //* merge two list
    l1.merge(l2);

    // accessing previou and next
    cout << *it << endl;

    auto _next = next(it);
    auto _prev = prev(it);

    cout << *_next << endl;
    cout << *_prev << endl;

return 0;
}