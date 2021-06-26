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
    int n, t, k;
    cin >> n >> t;

    int l = 1;
    int r = n;
    cout.flush();

    int cur;
    while (t--)
    {
        cin >> k;
        while (l < r)
        {
            int m = (r + l) / 2;                 // 4
            cout << "? " << l << ' ' << m << el; // 4 4
            cout.flush();
            cin >> cur;
            int cntL = m - l + 1 - cur; // 0

            if (cntL < k)
            {
                k -= cntL; // k = 1
                l = m + 1; // l = 4
            }
            else       // cnt >= k
                r = m; // 5
        }

        cout << "! " << l << endl;
        cout.flush();
        l = 1;
        r = n;
    }
    return 0;
}