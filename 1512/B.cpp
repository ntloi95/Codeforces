#include <bits/stdc++.h>
#define ll long long
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

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        int x1 = -1, y1, x2, y2;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == '*')
                {
                    if (x1 == -1)
                    {
                        x1 = i;
                        y1 = j;
                    }
                    else
                    {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }

        if (x1 == x2)
        {
            x2 = (x2 + 1) % n;
        }
        if (y1 == y2)
        {
            y2 = (y2 + 1) % n;
        }

        v[x1][y2] = '*';
        v[x2][y1] = '*';
        v[x1][y1] = '*';
        v[x2][y2] = '*';
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << el;
        }
    }
    return 0;
}