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
const int N = 2e3 + 10;
const int MOD = 1e9 + 7;

ll memo[N][N];

ll dp(const vi &a, int l, int r)
{
    if (memo[l][r] != -1)
    {
        return memo[l][r];
    }

    if (l == r)
    {
        return 0;
    }

    return memo[l][r] = a[r] - a[l] + min(dp(a, l + 1, r), dp(a, l, r - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end()); // 1, 2, 3
    memset(memo, -1, sizeof memo);
    cout << dp(a, 0, n - 1);
    return 0;
}