#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 111;
int cnt[N];
int id[N];
int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        memset(id, 0, sizeof(id));

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
            id[x] = i + 1;
        }

        for (int i = 1; i <= 100; i++)
        {
            if (cnt[i] == 1)
            {
                cout << id[i] << endl;
            }
        }
    }
    return 0;
}