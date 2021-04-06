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

    vector<int> dp(n, 0);
    vector<int> pre(n);

    int ansLen = 0;
    int ansId = -1;
    for (int i = 0; i < n; i++)
    {
        int id = -1;
        int maxLen = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && dp[j] > maxLen)
            {
                id = j;
                maxLen = dp[j];
            }
        }

        dp[i] = maxLen + 1;
        pre[i] = id;

        if (dp[i] > ansLen)
        {
            ansLen = dp[i];
            ansId = i;
        }
    }

    cout << ansLen << endl;
    vector<int> ans;
    while (ansId != -1)
    {
        ans.push_back(a[ansId]);
        ansId = pre[ansId];
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}