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
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int32_t main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vi a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    vector<vector<ii>> e(n, vector<ii>());
    vector<bool> v(n, false);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j] == 0)
                {
                    e[i].push_back({abs(i - j), j});
                }
            }
        }

        // sort(e[i].begin(), e[i].end());
    }

    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            int minDis = INT_MAX;
            int minId;

            for (int j = 0; j < e[i].size(); j++)
            {
                if (!v[e[i][j].se])
                {
                    if (minDis > e[i][j].fi)
                    {
                        minDis = e[i][j].fi;
                        minId = e[i][j].se;
                    }
                }
            }

            ans1 += minDis;
            v[minId] = true;
        }
    }

    e = vector<vector<ii>>(n, vector<ii>());
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (a[j] == 0)
                {
                    e[i].push_back({abs(i - j), j});
                }
            }
        }

        // sort(e[i].begin(), e[i].end());
    }

    int ans2 = 0;
    fill(v.begin(), v.end(), false);
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1)
        {
            int minDis = INT_MAX;
            int minId;

            for (int j = 0; j < e[i].size(); j++)
            {
                if (!v[e[i][j].se])
                {
                    if (minDis > e[i][j].fi)
                    {
                        minDis = e[i][j].fi;
                        minId = e[i][j].se;
                    }
                }
            }

            ans2 += minDis;
            v[minId] = true;
        }
    }

    cout << min(ans1, ans2);

    return 0;
}