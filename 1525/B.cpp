#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define gcd __gcd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int32_t main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        vi a(n);

        bool isSort = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != (i + 1))
            {
                isSort = false;
            }
        }

        if (isSort)
        {
            cout << 0 << endl;
            continue;
        }

        if (a[0] == 1 || a[n - 1] == n)
        {
            cout << 1 << endl;
            continue;
        }

        if (a[0] == n && a[n - 1] == 1)
        {
            cout << 3 << endl;
            continue;
        }

        cout << 2 << endl;
    }
    return 0;
}