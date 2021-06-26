#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10000;

int main()
{
    int nTest;
    cin >> nTest;

    while (nTest--)
    {
        ll x;
        cin >> x;

        bool yes = false;
        for (ll a = 1; a < N; a++)
        {
            ll b = cbrt(x - a * a * a);
            if (a * a * a + b * b * b == x && b > 0)
            {

                yes = true;
                break;
            }
        }

        if (yes)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}