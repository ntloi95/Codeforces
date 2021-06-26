#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 50;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int sz = r - l + 1;
        int down = sz * (sz + 1) / 2;
        int up = n * (n + 1) / 2 - ((n - sz) * (n - sz + 1)) / 2;

        if (s < down || s > up)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> v(sz);
        for (int i = 0; i < sz; i++)
        {
            v[i] = i + 1;
        }

        int cur = down;
        int id = sz - 1;
        int limitId = n;
        while (cur != s)
        {
            v[id]++;
            cur++;

            if (v[id] == limitId)
            {
                id--;
                limitId--;
            }
        }

        map<int, bool> hash;
        for (int i = 0; i < sz; i++)
        {
            hash[v[i]] = true;
        }

        vector<int> remain;
        for (int i = 1; i <= n; i++)
        {
            if (!hash[i])
            {
                remain.push_back(i);
            }
        }

        int it = 0;
        for (; it < l - 1; it++)
        {
            cout << remain[it] << ' ';
        }

        for (int i = 0; i < sz; i++)
        {
            cout << v[i] << ' ';
        }

        for (; it < remain.size(); it++)
        {
            cout << remain[it] << ' ';
        }

        cout << endl;
    }
    return 0;
}