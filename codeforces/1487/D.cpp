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
const int N = 1e9;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    int sqrtN = sqrt(2 * N - 1);
    map<int, int> ans;
    int cnt = 0;
    set<int> keys;
    for (int a = 1; a <= sqrtN; a++)
    {
        int b = (a * a - 1) / 2;
        int c = a * a - b;

        if ((a * a + b * b == c * c) && (a * a - b == c) && (b >= a) && (c >= b))
        {
            cnt++;
            ans[c] = cnt;
            keys.insert(c);
        }
    }

    multitest
    {
        int n;
        cin >> n;

        auto it = keys.upper_bound(n);
        it--;
        cout << ans[*it] << el;
    }

    return 0;
}