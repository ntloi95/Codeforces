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
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 50;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vvi v(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        int s = v[i][i] - 1;
        int curI = i; // 2
        int curJ = i; // 2
        while (s--)
        {
            if (curJ - 1 >= 0 && v[curI][curJ - 1] == 0)
            {
                curJ--;
                v[curI][curJ] = v[i][i];
            }
            else
            {
                curI++;
                v[curI][curJ] = v[i][i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}