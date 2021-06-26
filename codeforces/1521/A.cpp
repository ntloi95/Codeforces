#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define cgd __cgd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        ll a, b;
        cin >> a >> b;

        if (b == 1)
        {
            cout << "NO" << el;
            continue;
        }

        if (b == 2)
        {
            cout << "YES" << el << 3 * a << ' ' << a << ' ' << a * 4 << el;
            continue;
        }

        cout << "YES" << el << a * (b - 1) << ' ' << a << ' ' << a * b << el;
    }
    return 0;
}