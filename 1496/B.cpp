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
const int N = 50;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n, k;
        cin >> n >> k;
        set<int> s;
        int mex;

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
            mx = max(mx, x);
        }

        if (n == (mx + 1) || k == 0)
        {
            cout << n + k << el;
            continue;
        }

        int sz = min(n, mx);
        for (int i = 0; i <= sz; i++)
        {
            if (s.count(i) == 0)
            {
                mex = i;
                break;
            }
        }

        int v = (mex + mx + 1) / 2;
        if (s.count(v) == 0)
        {
            n++;
        }
        cout << n << el;
    }
    return 0;
}