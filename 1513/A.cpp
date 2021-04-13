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
        int n, k;
        cin >> n >> k;

        int p = (n - 1) / 2;
        if (k > p)
        {
            cout << -1 << el;
            continue;
        }

        vector<int> v(n, 0);
        for (int i = 0; i < k; i++)
        {
            v[i * 2 + 1] = n - i;
        }

        int x = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                v[i] = x++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << ' ';
        }
        cout << el;
    }
    return 0;
}