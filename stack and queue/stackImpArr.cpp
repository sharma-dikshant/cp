//* stack implementation using arrays

#include <bits/stdc++.h>
using namespace std;

class stackImp
{
public:
    int topIdx = -1;
    int st[100];

    void push(int num)
    {
        if (topIdx >= 99)
        {
            cout << "overflow!" << endl;
            return;
        }

        topIdx += 1;
        st[topIdx] = num;
    }

    int top()
    {
        if (topIdx == -1)
        {
            cout << "Empty!" << endl;
            return -1;
        }
        return st[topIdx];
    }

    void pop()
    {
        if (topIdx == -1)
        {
            cout << "Empty!" << endl;
            return;
        }
        topIdx -= 1;
    }

    int size()
    {
        return topIdx + 1;
    }
};

int main()
{
    stackImp st;
    st.push(100);
    st.push(200);

    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;

    return 0;
}