#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b)
    {
        cin >> x;
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;
    vector<int> ans;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j] == dp[i][j - 1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << ' ';
    }

    return 0;
}