#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 200001;
ii preSum[N];
int minID[N];
int debugCnt = 0;
int a[N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int x;
        cin >> x;
        preSum[0].fi = x;
        preSum[0].se = 0;
        ll maxSum = x;
        a[0] = x;

        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;

            preSum[i].fi = preSum[i - 1].fi + x;
            preSum[i].se = i;
            maxSum = max(maxSum, preSum[i].fi);

            a[i] = x;
        }

        ll sum = preSum[n - 1].fi;

        sort(preSum, preSum + n);
        minID[n - 1] = preSum[n - 1].se;
        for (int i = n - 2; i >= 0; i--)
        {
            minID[i] = min(minID[i + 1], preSum[i].se);
        }

        for (int i = 0; i < m; i++)
        {

            int x;
            cin >> x;

            debugCnt++;
            // if (debugCnt == 257)
            // {
            //     cout << n << '_';
            //     for (int i = 0; i < n; i++)
            //     {
            //         cout << a[i] << '_';
            //     }

            //     cout << "__" << x;
            // }

            if (x > maxSum && sum <= 0)
            {
                cout << -1 << ' ';
                continue;
            }

            ll rounds;
            if (sum == 0 || maxSum >= x)
            {
                rounds = 0;
            }
            else
            {
                rounds = max(0LL, ((x - maxSum + sum - 1) / sum));
            }

            ll res = rounds * n;
            x -= rounds * sum;

            auto it = lower_bound(preSum, preSum + n, ii(x, 0));

            res += minID[it - preSum];

            cout << res << ' ';
        }

        cout << endl;
    }

    return 0;
}