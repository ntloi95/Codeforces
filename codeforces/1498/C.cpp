#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1005;
const int MOD = 1000000007;
ll dp[N][N];

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= n; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 1; i <= k; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 2; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][n - j]) % MOD;
            }
        }

        cout << dp[k][n] << endl;
    }
    return 0;
}