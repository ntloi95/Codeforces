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
const int N = 50;
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
        bool ans = true;
        vi m(n / 3);
        vi t(n * 2 / 3);
        int im = 0, it = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'M')
            {
                if (im == n / 3)
                {
                    ans = false;
                    break;
                }
                m[im++] = i;
            }
            else
            {
                if (it == n * 2 / 3)
                {
                    ans = false;
                    break;
                }
                t[it++] = i;
            }
        }

        if (!ans)
        {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < n / 3; i++)
        {
            if (m[i] < t[i] || m[i] > t[i + n / 3])
            {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << el;
    }
    return 0;
}