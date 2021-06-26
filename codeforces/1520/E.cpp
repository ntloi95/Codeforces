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

ll solve(int p, string s)
{
    ll res = 0;
    int des = p - 1;
    for (int i = p - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            res += des - i;
            des--;
        }
    }

    des = p + 1;
    for (int i = p + 1; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            res += i - des;
            des++;
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        int cnt = 0;
        vi pos(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                cnt++;
                pos[cnt] = i;
            }
        }

        if (cnt % 2)
        {
            ans = solve(pos[cnt / 2 + 1], s);
        }
        else
        {
            ans = min(solve(pos[cnt / 2], s), solve(pos[cnt / 2 + 1], s));
        }

        cout << ans << el;
    }
    return 0;
}