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
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 50;
const int MOD = 1e9 + 7;

// 0, 0, 0, 1
int edge(int x1, int y1, int x2, int y2, const vvi &edgeH, const vvi &edgeV)
{
    if (x2 < x1)
    {
        swap(x1, x2);
    }

    if (y2 < y1)
    {
        swap(y1, y2);
    }

    if (x1 == x2)
    {
        return edgeH[x1][y1];
    }

    return edgeV[x1][y1];
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << -1 << ' ';
            }
            cout << endl;
        }
        return 0;
    }

    vvi edgeH(n, vi(m - 1));
    vvi edgeV(n - 1, vi(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cin >> edgeH[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> edgeV[i][j];
        }
    }

    vvi dp(n * m, vi(k, 0));

    for (int i = 1; i <= k / 2; i++)
        for (int j = 0; j < n * m; j++)
        {
            int x1 = j / m;     // 0
            int y1 = j % m;     // 0
            dp[j][i] = INT_MAX; // dp[0][1] = INT_MAX
            for (int d = 0; d < 4; d++)
            {
                int x2 = x1 + dx[d]; // 0
                int y2 = y1 + dy[d]; // 1

                if (x2 < n && x2 >= 0 && y2 < m && y2 >= 0) //
                {
                    dp[j][i] = min(dp[j][i], dp[x2 * m + y2][i - 1] + edge(x1, y1, x2, y2, edgeH, edgeV) * 2);
                    // dp[0][1] = 0 +
                }
            }
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i * m + j][k / 2] << ' ';
        }
        cout << endl;
    }
    return 0;
}