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
        vector<ll> x(n);
        vector<ll> y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        if (n & 1)
        {
            cout << 1 << el;
            continue;
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << el;
    }
    return 0;
}