#include <bits/stdc++.h>
using namespace std;

class queueImp
{
public:
    int qu[100];
    int start = -1;
    int end = -1;
    int totalEl = 0;

    void push(int num)
    {
        if (totalEl == 100)
        {
            cout << "OverFlow!" << endl;
        }
        else if (start == -1 and end == -1)
        {
            start += 1;
            end += (end + 1) % 100;
            qu[end] = num;
            totalEl++;
        }
        else
        {
            end += 1;
            qu[end] = num;
            totalEl++;
        }
    }

    int size()
    {
        return totalEl;
    }

    void pop()
    {
        if (totalEl == 0)
        {
            cout << "empty!" << endl;
            return;
        }
        else if (totalEl == 1)
        {
            start = -1;
            end = -1;
        }
        start += (start + 1) % 100;
        totalEl--;
    }

    int top()
    {
        if (totalEl == 0)
        {
            cout << "empty!" << endl;
            return -1;
        }
        else
        {
            return qu[start];
        }
    }
};

int main()
{
    queueImp q;
    cout << q.size() << endl;
    cout << q.top() << endl;
    q.pop();
    q.push(100);
    cout << q.top() << endl;
    return 0;
}