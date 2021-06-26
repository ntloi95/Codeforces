#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 300005;
int cnt0[N];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        memset(cnt0, 0, sizeof(cnt0));

        cnt0[0] = a[0] == '0';
        for (int i = 1; i < n; i++)
        {
            cnt0[i] = cnt0[i - 1] + (a[i] == '0');
        }

        bool ans = true;
        bool flag = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if ((a[i] == b[i]) == flag)
            {
                if (cnt0[i] != i + 1 - cnt0[i])
                {
                    cout << "NO" << endl;
                    ans = false;
                    break;
                }
                flag = !flag;
            }
        }

        if (ans)
            cout << "YES" << endl;
    }
    return 0;
}