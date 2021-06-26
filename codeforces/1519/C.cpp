#include <bits/stdc++.h>
#define ll long long
// #define int long long
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

int32_t main()
{
    // ios::sync_with_stdio(false);
    multitest
    {
        int n;
        scanf("%d", &n);
        vi u(n), s(n);

        for (int &x : u)
        {
            scanf("%d", &x);
        }

        ll sum = 0;
        for (int &x : s)
        {
            scanf("%d", &x);
            sum += x;
        }

        map<int, vi> g;
        for (int i = 0; i < n; i++)
        {
            if (g.count(u[i] == 0))
            {
                g[u[i]] = vi();
            }

            g[u[i]].push_back(s[i]);
        }

        int maxSize = 0;
        map<int, vector<ll>> remains;
        for (auto &[uni, skill] : g)
        {
            sort(skill.begin(), skill.end(), greater<int>());
            maxSize = max(maxSize, (int)skill.size());

            remains[uni] = vector<ll>(skill.size(), 0);
            remains[uni][0] = skill.back();
            for (int i = 1; i < skill.size(); i++)
            {
                remains[uni][i] = remains[uni][i - 1] + skill[skill.size() - 1 - i];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            ll sub = 0;
            vi deleteUni;
            for (auto &[uni, skill] : g)
            {
                int remain = skill.size() % i;
                if (remain != 0)
                    sub += remains[uni][remain - 1];
                if (i >= skill.size())
                {
                    deleteUni.push_back(uni);
                }
            }

            printf("%lld ", sum - sub);
            for (auto &uni : deleteUni)
            {
                g.erase(uni);
                sum -= remains[uni].back();
            }
        }
        puts("");
    }
    return 0;
}