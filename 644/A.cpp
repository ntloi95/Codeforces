#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 105;
int m[N][N];

int main()
{
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;

    int d = 1;
    int r = 2;

    for (int i = 0; i < a; i++)
    {
        for (int j = i % 2; j < b && d <= n; j += 2)
        {
            m[i][j] = d;
            d += 2;
        }
        for (int j = 1 - i % 2; j < b && r <= n; j += 2)
        {
            m[i][j] = r;
            r += 2;
        }
    }

    if (max(r - 2, d - 2) < n)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}