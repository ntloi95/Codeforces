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
const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x : v)
        {
            cin >> x;
        }

        int mi = *min_element(v.begin(), v.end());
        bool isContinue = false;
        ll cnt = 0;
        for (int x : v)
        {
            if (x == mi)
            {
                cnt++;
            }
            if (mi != (mi & x))
            {
                cout << 0 << endl;
                isContinue = true;
                break;
            }
        }

        if (isContinue)
        {
            continue;
        }

        ll ans = (cnt * (cnt - 1)) % MOD;
        for (int i = 1; i <= n - 2; i++)
        {
            ans = (ans * i) % MOD;
        }

        cout << ans << endl;
    }
    return 0;
}