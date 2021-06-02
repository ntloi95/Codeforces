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
        int k;
        cin >> k;

        int w = 100 - k;
        int g = gcd(k, w);

        if (k == 100)
        {
            cout << 1 << endl;
            continue;
        }
        w /= g;
        k /= g;
        cout << w + k << endl;
    }
    return 0;
}