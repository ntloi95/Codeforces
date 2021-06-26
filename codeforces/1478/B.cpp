#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int m[10][11] = {0};

    for (int i = 1; i < 10; i++)
    {
        for (int j = 10; j > 0; j--)
        {
            int p = i * j;
            m[i][p % 10] = p;
        }
    }

    int nTC;
    cin >> nTC;
    while (nTC--)
    {
        int n, d, a;
        cin >> n >> d;
        for (int i = 0; i < n; i++)
        {
            cin >> a;

            if (a >= 10 * d)
            {
                puts("YES");
                continue;
            }

            if (a < m[d][a % 10])
            {
                puts("NO");
                continue;
            }

            puts("YES");
        }
    }
    return 0;
}