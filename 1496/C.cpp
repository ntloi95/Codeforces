#include <bits/stdc++.h>
#define ll long long
#define ld double
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
        int n;
        cin >> n;
        vector<ld> x(n);
        vector<ld> y(n);

        int ix = 0;
        int iy = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            int tx, ty;
            cin >> tx >> ty;

            if (tx)
            {
                x[ix++] = abs(tx);
            }
            else
            {
                y[iy++] = abs(ty);
            }
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ld ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += hypot(x[i], y[i]);
        }

        printf("%.15f\n", ans);
    }
    return 0;
}