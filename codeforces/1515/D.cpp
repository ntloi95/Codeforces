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

int cntPair(vi v)
{
    sort(v.begin(), v.end());
    int cnt = 0;

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            cnt++;
            i++;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n, l, r;
        cin >> n >> l >> r;

        vi lc(l), rc(r);
        multiset<int> lSet;
        for (auto &x : lc)
        {
            cin >> x;
            lSet.insert(x);
        }

        int id = 0;
        for (int i = 0; i < r; i++)
        {
            int x;
            cin >> x;

            auto it = lSet.find(x);
            if (it != lSet.end())
            {
                lSet.erase(it);
                l--;
            }
            else
            {
                rc[id++] = x;
            }
        }
        r = id;

        lc.resize(l);
        rc.resize(r);
        id = 0;
        for (auto x : lSet)
        {
            lc[id++] = x;
        }

        int res = 0;
        if (l > r)
        {
            res += (l - r) / 2;
            int p = cntPair(lc);
            if (p >= res)
            {
                res += r;
            }
            else
            {
                res += (r + res) - p;
            }
        }
        else if (l < r)
        {
            res += (r - l) / 2;
            int p = cntPair(rc);
            if (p >= res)
            {
                res += l;
            }
            else
            {
                res += (l + res) - p;
            }
        }
        else
        {
            res += l;
        }

        cout << res << el;
    }
    return 0;
}