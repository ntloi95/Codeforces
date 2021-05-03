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
        int n, x;
        cin >> n >> x;
        vi v(n);
        int sum = 0;
        for (auto &a : v)
        {
            cin >> a;
            sum += a;
        }

        if (sum == x)
        {
            cout << "NO" << el;
            continue;
        }

        cout << "YES" << el;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            int a = v[i];
            if (cur + a == x)
            {
                cout << v[n - 1] << ' ';
                cur += v[n - 1];
                n--;
                i--;
            }
            else
            {
                cout << a << ' ';
                cur += a;
            }
        }
        cout << el;
    }
    return 0;
}