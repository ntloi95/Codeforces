#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define gcd __gcd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int32_t main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &x : a)
        {
            cin >> x;
        }

        sort(a.begin(), a.end());
        int res = n;
        int mi = INT_MAX;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > 0)
            {
                if (a[i] > mi)
                {
                    res = i; // Khong lay a[i]
                }
                else
                {
                    res = i + 1;
                }
                break;
            }

            if (i != 0)
            {
                mi = min(mi, abs(a[i] - a[i - 1]));
            }
        }

        cout << res << endl;
    }
    return 0;
}