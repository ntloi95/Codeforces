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
        int n;
        cin >> n;
        int like = 0;
        for (int i = 0; i < n; i++)
        {
            int r;
            cin >> r;
            if (r != 2)
            {
                like++;
            }
        }

        cout << like << el;
    }
    return 0;
}