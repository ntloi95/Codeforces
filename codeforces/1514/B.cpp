#include <bits/stdc++.h>
#define ll long long
#define ld double
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
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        ll n, k;
        cin >> n >> k;

        ll res = 1;
        for (int i = 0; i < k; i++)
        {
            res *= n;
            res %= MOD;
        }

        cout << res << endl;
    }
    return 0;
}