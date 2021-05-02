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
        ll n;
        cin >> n;
        if (n % 2050)
        {
            cout << -1 << el;
            continue;
        }

        n /= 2050;
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }
        cout << res << el;
    }
    return 0;
}