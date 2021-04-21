#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define fi first
#define se second
#define el endl

#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 50;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        ll n, k;
        cin >> n >> k;

        if (n == 1)
        {
            cout << 0 << el;
            continue;
        }

        ll twoPowerK = 1;
        for (int i = 0; i < k - 1; i++)
        {
            twoPowerK <<= 1;
            twoPowerK %= MOD;
        }

        ll res = n * (n - 1);
        res %= MOD;
        res *= twoPowerK - 1;
        res %= MOD;
        res += n;
        res %= MOD;
        cout << res << el;
    }
    return 0;
}