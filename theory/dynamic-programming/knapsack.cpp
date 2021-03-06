#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    vector<int> w(n);
    for (auto &x : w)
    {
        cin >> x;
    }

    // dp[i][j] = max value of first i items with limit j weight.
    // dp[i][0] = 0;
    // dp[0][i] = 0;
    // dp[i][j] = dp[i-1][j] if weight[i] > j;
    //          = dp[i-1][j-weight[i]] + value[i] if weight <= j;
    // res = dp[n][m];

    // trace back.
    // if dp[i][j] == dp[i-1][j] => means we did not select item i.
    // else we selected items i.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1])
            {
                dp[i][j] = max(dp[i][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }

    cout << dp[n][m] << endl;
    int i = n;
    int j = m;
    vector<int> res;
    while (i != 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            res.push_back(i - 1);
            j -= w[i - 1];
        }
        i--;
    }

    reverse(res.begin(), res.end());
    for (auto x : res)
    {
        cout << x << ' ';
    }
    return 0;
}