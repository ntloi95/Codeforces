#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 200001;
ii a[N];
ll s[N];
int res[N];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[i].fi = x;
            a[i].se = i;
        }

        sort(a + 1, a + 1 + n);
        int lastLoser = 0;
        for (int i = 1; i < n; i++)
        {
            s[i] = s[i - 1] + a[i].fi;

            if (s[i] < a[i + 1].fi)
            {
                lastLoser = i;
            }
        }

        int nRes = 0;
        for (int i = lastLoser + 1; i <= n; i++)
        {
            res[nRes++] = a[i].se;
        }

        sort(res, res + nRes);

        cout << nRes << endl;
        for (int i = 0; i < nRes; i++)
        {
            cout << res[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}