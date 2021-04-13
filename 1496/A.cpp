#include <bits/stdc++.h>
#define ll long long
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (n < 2 * k + 1)
        {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == s[n - 1 - i])
            {
                k--;
            }
            else
            {
                break;
            }
        }

        if (k < 1)
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