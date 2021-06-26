#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int mx;
        cin >> mx;
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;

            if (x < mx)
            {
                int k = mx - x;
                int c = 0;
                while (k)
                {
                    k /= 2;
                    c++;
                }
                ans = max(ans, c);
            }
            else
            {
                mx = x;
            }
        }

        cout << ans << endl;
    }
    return 0;
}