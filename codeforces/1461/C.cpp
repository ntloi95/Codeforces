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
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for (int &x : v)
        {
            cin >> x;
        }

        int k = n;
        while (k > 0 && v[k - 1] == k)
        {
            k--;
        }

        double res = 1;
        for (int i = 0; i < m; i++)
        {
            int r;
            double p;
            cin >> r >> p;

            if (r >= k)
            {
                res *= (1 - p);
            }
        }

        cout << fixed << setprecision(10);

        if (k == 0)
            cout << 1.0 << el;
        else
            cout << 1 - res << el;
    }
    return 0;
}