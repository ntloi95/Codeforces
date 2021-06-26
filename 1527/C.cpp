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
        map<int, int> cnt;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int ans = 0;
        for (auto [k, v] : cnt)
        {
            if (v > 1)
            {
                int cur = 0;
                int t = 1;
                for (int i = v; i >= 2; i--)
                {
                    cur += i * (i - 1) * t;
                    t *= i;
                }
                cur /= 2;
                ans *= cur;
            }
        }

        cout << ans << endl;
    }
    return 0;
}