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

    // dp[i][j] = longest length of prefix first i elements in a, first j elemets in b
    // dp[0][0] = 0;
    // dp[i][j] = dp[i-1][j-1] + 1 if (a[i] == a[j])
    //          = max(dp[i-1][j], dp[i][j-1]) if (a[i] != a[j])
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    vector<int> ans;
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans.push_back(a[i - 1]);
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