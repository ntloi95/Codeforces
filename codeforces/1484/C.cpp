#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

bool cmpSize(pair<int, vector<int>> x, pair<int, vector<int>> y)
{
    return x.se.size() < y.se.size();
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, vector<int>>> d(m, make_pair(0, vector<int>()));
        for (int i = 0; i < m; i++)
        {
            int k;
            cin >> k;
            d[i].fi = i;
            d[i].se.resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> d[i].se[j];
            }
        }

        sort(d.begin(), d.end(), cmpSize);
        vector<int> res(m);
        vector<int> cnt(n + 1, 0);
        bool yes = true;

        for (auto day : d)
        {
            int minCnt = INT_MAX;
            int bestId = 0;
            for (auto f : day.second)
            {
                if (minCnt > cnt[f])
                {
                    minCnt = cnt[f];
                    bestId = f;
                }
            }

            res[day.fi] = bestId;
            cnt[bestId]++;

            if (cnt[bestId] > n / 2)
            {
                yes = false;
                break;
            }
        }

        if (!yes)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (auto x : res)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}