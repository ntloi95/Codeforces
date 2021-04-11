#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 200010;
ll a[N];

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n + 2; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(a, a + n + 2);

        int mx = a[n + 1];
        int mx2 = a[n];
        sum -= mx;

        bool isContinue = false;
        for (int i = 0; i < n + 1; i++)
        {
            ll cur = sum - a[i];
            if (cur == mx)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << a[j] << ' ';
                }

                for (int j = i + 1; j < n + 1; j++)
                {
                    cout << a[j] << ' ';
                }
                isContinue = true;
                cout << endl;
                break;
            }
        }

        if (isContinue)
        {
            continue;
        }

        if (mx2 * 2 == sum)
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << ' ';
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}