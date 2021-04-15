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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<int> l(m, 0);
    vector<int> r(m, 0);

    int i = 0;
    for (int j = 0; j < m; j++)
    {
        while (t[j] != s[i])
        {
            i++;
        }

        l[j] = i;
        i++;
    }

    i = n - 1;
    for (int j = m - 1; j >= 0; j--)
    {
        while (t[j] != s[i])
        {
            i--;
        }
        r[j] = i;
        i--;
    }

    int ans = 0;
    for (int i = 0; i < m - 1; i++)
    {
        ans = max(ans, r[i + 1] - l[i]);
    }
    cout << ans;

    return 0;
}