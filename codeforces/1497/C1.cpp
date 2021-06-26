#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define mutitest \
    int t;       \
    cin >> t;    \
    while (t--)
#define fi first
#define se second
using namespace std;
const int N = 50;

int main()
{
    ios::sync_with_stdio(false);
    mutitest
    {
        int n, k;
        cin >> n >> k;

        if (n % 2)
        {
            cout << n / 2 << ' ' << n / 2 << ' ' << 1 << endl;
        }
        else
        {
            if (n % 4 == 0)
            {
                cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << endl;
            }
            else
            {
                cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << endl;
            }
        }
    }
    return 0;
}