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

ll gen(int len, int d)
{
    ll num = 0;

    for (int i = 0; i < len; i++)
    {
        num = num * 10 + d;
    }

    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        ll n;
        cin >> n;

        int len = to_string(n).length();

        int ans = (len - 1) * 9;
        for (int i = 0; i < 9; i++)
        {
            if (n >= gen(len, i + 1))
            {
                ans++;
            }
        }

        cout << ans << el;
    }
    return 0;
}