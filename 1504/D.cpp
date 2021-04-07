#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 105;
int res[N][N];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int x1 = 1, y1 = 1;
    int x2 = 1, y2 = 2;
    for (int i = 0; i < n * n; i++)
    {
        int a;
        cin >> a;

        if (x1 > n)
        {
            int c = 2;
            if (a == 2)
            {
                c = 3;
            }

            cout << c << ' ' << x2 << ' ' << y2 << endl;
            cout.flush();
            y2 += 2;
            if (y2 > n)
            {
                x2++;
                y2 = (x2 % 2) ? 2 : 1;
            }

            continue;
        }

        if (x2 > n)
        {
            int c = 1;
            if (a == 1)
            {
                c = 3;
            }

            cout << c << ' ' << x1 << ' ' << y1 << endl;
            cout.flush();

            y1 += 2;
            if (y1 > n)
            {
                x1++;
                y1 = (x1 % 2) ? 1 : 2;
            }
            continue;
        }

        if (a != 1)
        {
            cout << 1 << ' ' << x1 << ' ' << y1 << endl;
            cout.flush();

            y1 += 2;
            if (y1 > n)
            {
                x1++;
                y1 = (x1 % 2) ? 1 : 2;
            }
        }
        else if (a != 2)
        {
            cout << 2 << ' ' << x2 << ' ' << y2 << endl;
            cout.flush();
            y2 += 2;
            if (y2 > n)
            {
                x2++;
                y2 = (x2 % 2) ? 2 : 1;
            }
        }
    }

    return 0;
}