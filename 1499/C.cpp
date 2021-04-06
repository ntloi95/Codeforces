#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 100005;
int c[N];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        ll res = LLONG_MAX;

        int id1 = 0;
        int id2 = 1;

        ll mi1 = c[0];
        ll mi2 = c[1];

        ll cur = c[0];

        for (int i = 1; i < n; i++)
        {
            cur += c[i];
            if (i % 2 == 0)
            {
                if (c[i] < mi1)
                {
                    mi1 = c[i];
                    id1 = i;
                }
            }
            else
            {
                if (c[i] < mi2)
                {
                    mi2 = c[i];
                    id2 = i;
                }
            }

            res = min(res, cur + mi1 * (n - 1 - i / 2) + mi2 * (n - 1 - (i - 1) / 2));
        }

        cout << res << endl;
    }

    return 0;
}