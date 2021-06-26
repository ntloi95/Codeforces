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
const int N = 1e9;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    set<int> yes;
    for (int i = 1; 2 * i * i <= N; i++)
    {
        yes.insert(2 * i * i);
        yes.insert(4 * i * i);
    }

    multitest
    {
        int n;
        cin >> n;
        cout << (yes.count(n) != 0 ? "YES" : "NO") << el;
    }
    return 0;
}