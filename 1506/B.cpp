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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ans1 = 0;
        int i = 0;
        while (i < n)
        {
            if (s[i] == '*')
            {
                ans1++;
                break;
            }
            i++;
        }

        for (i = i + 1; i < n; i++)
        {
            int p = -1;
            for (int j = 0; j < k && i + j < n; j++)
            {
                if (s[i + j] == '*')
                {
                    p = i + j;
                }
            }

            if (p == -1)
            {
                break;
            }

            ans1++;
            i = p;
        }

        i = n - 1;
        int ans2 = 0;
        while (i >= 0)
        {
            if (s[i] == '*')
            {
                ans2++;
                break;
            }
            i--;
        }

        for (i = i - 1; i >= 0; i--)
        {
            int p = -1;
            for (int j = 0; j < k && i - j >= 0; j++)
            {
                if (s[i - j] == '*')
                {
                    p = i - j;
                }
            }

            if (p == -1)
            {
                break;
            }

            ans2++;
            i = p;
        }

        cout << min(ans1, ans2) << el;
    }
    return 0;
}