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
const int BIG_PRIME = 1500450271;

int32_t main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        vector<ll> a(n);

        for (auto &x : a)
        {
            cin >> x;
        }

        if (n == 1)
        {
            cout << 0 << el;
            continue;
        }

        vvi res;

        if (a[0] > a[1])
        {
            a[0] = BIG_PRIME;
            res.push_back(vi({0, 1, BIG_PRIME}));
            res[0].push_back(a[1]);
        }

        if (a[n - 1] > a[n - 2])
        {
            a[n - 1] = BIG_PRIME;
            res.push_back(vi({0, 1, BIG_PRIME}));
            res[0].push_back(a[1]);
        }
    }
    return 0;
}