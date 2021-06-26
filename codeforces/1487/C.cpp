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
const int N = 110;
const int MOD = 1e9 + 7;
int res[N][N];

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        memset(res, 0, sizeof res);
        int m = n * (n - 1) / 2;
        int w = m / n;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            for (int k = 0; k < w; k++, j++)
            {
                j %= n;
                res[i][j] = 1;
                res[j][i] = -1;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cout << res[i][j] << ' ';
            }
        }

        cout << el;
    }
    return 0;
}