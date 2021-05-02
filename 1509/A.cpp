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
        int n;
        cin >> n;

        vi v1, v2;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
            {
                v1.push_back(x);
            }
            else
            {
                v2.push_back(x);
            }
        }

        for (auto x : v1)
        {
            cout << x << ' ';
        }

        for (auto x : v2)
        {
            cout << x << ' ';
        }

        cout << el;
    }
    return 0;
}