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
        int t = 0;
        while (n)
        {
            t++;
            n /= 2;
        }
        cout << (1 << (t - 1)) - 1 << endl;
    }
    return 0;
}