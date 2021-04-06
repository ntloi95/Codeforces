#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1000005;
int fen[N], a[N], r[N], n;

void add(int x, int v)
{
    for (int i = x; i <= n; i += i & -i)
    {
        fen[i] += v;
    }
}

int get(int x)
{
    int ans = 0;
    for (int i = x; i; i -= i & -i)
    {
        ans += fen[i];
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt[a[i]]++;
        add(cnt[a[i]], 1);
        r[i] = cnt[a[i]];
    }

    ll res = 0;
    cnt.clear();
    for (int i = 0; i < n; i++)
    {
        add(r[i], -1);
        cnt[a[i]]++;
        res += get(cnt[a[i]] - 1);
    }

    cout << res;
    return 0;
}