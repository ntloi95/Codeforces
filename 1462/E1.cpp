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

        vector<ll> cnt(n + 3, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }

        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += cnt[i] * cnt[i + 1] * cnt[i + 2];
            res += cnt[i] * cnt[i + 1] * (cnt[i + 1] - 1) / 2;
            res += cnt[i] * cnt[i + 2] * (cnt[i + 2] - 1) / 2;

            res += cnt[i] * (cnt[i] - 1) * cnt[i + 1] / 2;
            res += cnt[i] * (cnt[i] - 1) * cnt[i + 2] / 2;
            res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        }

        cout << res << el;
    }
    return 0;
}