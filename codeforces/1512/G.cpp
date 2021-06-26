#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define el endl
#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 1e7 + 10;
ll d[N], ans[N];

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            d[j] += i;
        }

        if (d[i] < N && ans[d[i]] == 0)
        {
            ans[d[i]] = i;
        }
    }

    multitest
    {
        int n;
        cin >> n;
        if (ans[n] == 0)
        {
            cout << -1 << el;
        }
        else
        {
            cout << ans[n] << el;
        }
    }
    return 0;
}