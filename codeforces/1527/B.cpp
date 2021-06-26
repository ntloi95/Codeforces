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
        string s;
        cin >> s;

        int cnt0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cnt0++;
            }
        }

        bool isPalin = true;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                isPalin = false;
                break;
            }
        }

        if (isPalin)
        {
            if (cnt0 % 2 && cnt0 > 1)
            {
                cout << "ALICE" << endl;
                continue;
            }
            else
            {
                cout << "BOB" << endl;
            }
        }
        else
        {
            if (cnt0 == 2 && s[n / 2] == '0' && n % 2)
            {
                cout << "DRAW" << endl;
            }
            else
            {
                cout << "ALICE" << endl;
            }
        }
    }
    return 0;
}