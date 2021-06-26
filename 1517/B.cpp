#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define cgd __cgd

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
        vector<vector<int>> v(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
        }

        vector<vector<int>> res(n, vector<int>(m));

        for (int j = 0; j < m; j++)
        {
            int k = 0;
            for (int i = 1; i < n; i++)
            {
                if (v[i][0] < v[k][0])
                {
                    k = i;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (i == k)
                {
                    res[i][j] = v[i][0];
                    v[i].erase(v[i].begin());
                }
                else
                {
                    res[i][j] = v[i].back();
                    v[i].pop_back();
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << res[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}