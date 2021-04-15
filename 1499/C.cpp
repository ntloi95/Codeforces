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
        int n;
        cin >> n;
        vector<ll> c(n);
        for (auto &x : c)
        {
            cin >> x;
        }

        ll ans = c[0] * n + c[1] * n;
        ll pre = c[0] + c[1];
        int x = 0;
        int y = 1;

        for (int i = 2; i < n; i++)
        {
            if (i % 2)
            {
                if (c[i] < c[y])
                {
                    y = i;
                }
            }
            else
            {
                if (c[i] < c[x])
                {
                    x = i;
                }
            }

            pre += c[i];
            ll cur = pre + (n - i / 2 - 1) * c[x] + (n - (i - 1) / 2 - 1) * c[y];
            ans = min(ans, cur);
        }
        cout << ans << el;
    }
    return 0;
}