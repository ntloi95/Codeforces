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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int &x : v)
        {
            cin >> x;
        }

        int i = 0;
        while (k && (i < n - 1))
        {
            while ((v[i] != 0) && k)
            {
                v[i]--;
                v[n - 1]++;
                k--;
            }

            i++;
        }

        for (int x : v)
        {
            cout << x << ' ';
        }
        cout << el;
    }
    return 0;
}