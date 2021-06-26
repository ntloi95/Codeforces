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
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;

        int wc = k1 + k2;
        int bc = n * 2 - wc;

        if (w <= wc / 2 && b <= bc / 2)
        {
            cout << "YES" << el;
        }
        else
        {
            cout << "NO" << el;
        }
    }
    return 0;
}