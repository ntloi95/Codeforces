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
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for (int &x : v)
    {
        cin >> x;
        sum += x;
    }

    if (sum & 1)
    {
        cout << 0;
        return 0;
    }

    bitset<200000> b;
    b[0] = 1;
    for (int x : v)
    {
        b |= (b << x);
    }

    if (!b[sum / 2])
    {
        cout << 0;
        return 0;
    }

    int res = 0;
    int mi = 32;

    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        int bit = __builtin_ctz(x);

        if (mi > bit)
        {
            mi = bit;
            res = i + 1;
        }
    }

    cout << 1 << endl
         << res;

    return 0;
}