#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define el endl
#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 10;
const int M = 2e5 + 1;
const int MOD = 1e9 + 7;
ll cnt[N];
ll newCnt[N];
ll f[N][M];

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < N; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        cnt[i] = 1;
        f[i][0] = 1;
        for (int j = 1; j < M; j++)
        {
            newCnt[0] = cnt[9];
            newCnt[1] = (cnt[9] + cnt[0]) % MOD;
            for (int k = 2; k < N; k++)
            {
                newCnt[k] = cnt[k - 1];
            }

            memcpy(cnt, newCnt, sizeof(cnt));

            ll res = 0;
            for (int k = 0; k < N; k++)
            {
                res += cnt[k];
                res %= MOD;
            }

            f[i][j] = res;
        }
    }
    multitest
    {
        string n;
        int m;
        cin >> n >> m;
        ll res = 0;

        for (int i = 0; i < n.length(); i++)
        {
            int d = n[i] - '0';
            res += f[d][m];

            res %= MOD;
        }
        cout << res << el;
    }
    return 0;
}