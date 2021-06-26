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
        int n;
        cin >> n;
        string s;
        cin >> s;

        set<char> pre;
        bool yes = true;
        for (int i = 0; i < n; i++)
        {
            if (pre.count(s[i]))
            {
                yes = false;
                break;
            }
            if ((i + 1 < n) && s[i] != s[i + 1])
            {
                pre.insert(s[i]);
            }
        }

        cout << (yes ? "YES" : "NO") << el;
    }
    return 0;
}