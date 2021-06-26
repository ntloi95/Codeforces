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

        if (n == 2)
        {
            cout << -1 << el;
            continue;
        }

        vvi ans(n, vi(n));
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i][i] = cnt++;
        }

        for (int i = 1; i < n; i++)
        {
            int r = i;
            int c = 0;
            for (int j = 0; j < n - i; j++)
            {
                ans[r][c] = cnt++;
                r++;
                c++;
            }

            r = 0;
            c = i;
            for (int j = 0; j < n - i; j++)
            {
                ans[r][c] = cnt++;
                r++;
                c++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << el;
        }
    }
    return 0;
}