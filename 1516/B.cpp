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
const int N = 31;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int xo = 0;
        for (int &x : v)
        {
            cin >> x;
            xo ^= x;
        }

        if (xo == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        int cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cur ^= v[i];
            if (cur == xo)
            {
                cnt++;
                cur = 0;
            }
        }

        cout << ((cnt >= 2) ? "YES" : "NO") << endl;
    }
    return 0;
}