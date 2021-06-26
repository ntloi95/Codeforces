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
const int MOD = 998244353;
int D[N];
int32_t main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    /*
    f[i] = D(i) + sum(f[i], i: 0 -> n-1)
    */
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            D[j]++;
    }

    int sum = 2;
    int cur = 1;
    for (int i = 2; i <= n; i++)
    {
        cur = (D[i] + sum) % MOD;
        sum = (sum + cur) % MOD;
    }
    cout << cur;
    return 0;
}