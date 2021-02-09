#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        int n, k;
        ll p[111];
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        ll sum = p[0];
        ll res = 0;

        for (int i = 1; i < n; i++)
        {
            res = max(res, max(0LL, (p[i] * 100 + k - 1) / k - sum));
            sum += p[i];
        }
        cout << res << endl;
    }
    return 0;
}