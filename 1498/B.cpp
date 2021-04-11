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
const int N = 32;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n, w;
        cin >> n >> w;
        multiset<int> ws;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ws.insert(x);
        }

        int ans = 0;
        while (ws.size())
        {
            int d = 0;

            while (d < w && ws.size())
            {
                auto it = ws.upper_bound(w - d);
                if (it == ws.begin())
                {
                    break;
                }

                it--;

                d += *it;
                ws.erase(it);
            }

            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}