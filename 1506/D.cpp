#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define cgd __cgd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        multiset<ii> a;
        set<int> d;
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            d.insert(x);
            cnt[x]++;
        }

        for (auto x : d)
        {
            a.insert(ii(cnt[x], x));
        }

        while (a.size() > 1)
        {
            auto it = a.rbegin();
            auto mx = *it;
            it++;
            auto mx2 = *it;

            a.erase(mx);
            a.erase(mx2);

            if (mx.first > 1)
            {
                a.insert(ii(mx.first - 1, mx.second));
            }

            if (mx2.first > 1)
            {
                a.insert(ii(mx2.first - 1, mx2.second));
            }
        }

        int ans = 0;
        for (auto x : a)
        {
            ans += x.first;
        }
        cout << ans << el;
    }
    return 0;
}