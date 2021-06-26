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
const int N = 200005;
ll a[N];
ll b[N];
int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n, c;
        cin >> n >> c;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int j = 0; j < n - 1; j++)
        {
            cin >> b[j];
        }

        ll res = LLONG_MAX;
        ll mv = 0;
        ll r = 0;

        for (int i = 0; i < n; i++)
        {
            ll d = ((c - r) + a[i] - 1) / a[i];
            res = min(res, d + mv);

            if (r >= b[i])
            {
                r -= b[i];
                mv++;
            }
            else
            {
                mv += (b[i] - r + a[i] - 1) / a[i] + 1;
                r = ((b[i] - r + a[i] - 1) / a[i]) * a[i] + r - b[i];
            }
        }

        cout << res << endl;
    }
    return 0;
}