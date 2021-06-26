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
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
vi adj[N];
int l[N], r[N], f[N][2];

void dfs(int u, int p = -1)
{
    f[u][0] = 0;
    f[u][1] = 0;

    for (auto e : adj[u])
    {
        if (e == p)
            continue;
        dfs(e, u);
        f[u][0] += max(f[e][0] + abs(l[u] - l[e]), f[e][1] + abs(l[u] - r[e]));
        f[u][1] += max(f[e][0] + abs(r[u] - l[e]), f[e][1] + abs(r[u] - r[e]));
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i];
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1);

        cout << max(f[1][0], f[1][1]) << endl;
    }
    return 0;
}