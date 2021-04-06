#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500;

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        int n;
        int a[N];

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int small = min(a[i], a[i + 1]);
            int big = max(a[i], a[i + 1]);

            while (small * 2 < big)
            {
                small *= 2;
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}