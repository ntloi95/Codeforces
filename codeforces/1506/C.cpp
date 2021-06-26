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
        string a, b;
        cin >> a >> b;

        int n = a.size();
        int m = b.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int len = j - i + 1;
                string sub = a.substr(i, len);

                if (b.find(sub, 0) != string::npos)
                {
                    ans = max(ans, len);
                }
            }
        }

        cout << n + m - ans * 2 << el;
    }
    return 0;
}