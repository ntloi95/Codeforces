#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define cgd __cgd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        vi resMi(n, 0), resMx(n, 0);
        set<int> mi;
        set<int> mx;
        for (int i = 1; i <= n; i++)
        {
            mi.insert(i);
            mx.insert(i);
        }

        int x;
        cin >> x;
        resMx[0] = x;
        resMi[0] = x;
        mi.erase(x);
        mx.erase(x);

        int pre = x;
        for (int i = 1; i < n; i++)
        {
            cin >> x;
            if (pre != x)
            {
                resMi[i] = x;
                resMx[i] = x;
                mi.erase(x);
                mx.erase(x);
                pre = x;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (resMi[i] == 0)
            {
                int v = *mi.begin();
                resMi[i] = v;
                mi.erase(v);
            }

            cout << resMi[i] << ' ';
        }

        cout << el;

        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (resMx[i])
            {
                p = resMx[i];
            }
            else
            {
                auto it = mx.upper_bound(p);
                it--;
                resMx[i] = *it;
                mx.erase(*it);
            }

            cout << resMx[i] << ' ';
        }
        cout << el;
    }
    return 0;
}