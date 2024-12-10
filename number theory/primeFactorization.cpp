#include <iostream>
using namespace std;

// brute force O(n)

void factorize(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            cout << i << "^" << cnt << ",";
        }
    }
}

/* //!optimization
OBS: once N is reduced to a prime number, then the only factor of that number will be the number
itself.

If a number does'nt have any factor till sqrt(N) then it is a prime number.
*/

// O(sqrt(N))
void op_factorize(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n = n / i;
            }
            cout << i << "^" << cnt << ",";
        }
    }

    if (n != 1)
    {
        cout << n << "^" << 1 << ",";
    }
}

int main()
{
    int n;
    cin >> n;
    factorize(n);
    op_factorize(n);
    return 0;
}