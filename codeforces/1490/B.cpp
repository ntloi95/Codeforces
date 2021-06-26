#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int r[3] = {0};
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            r[x % 3]++;
        }

        int ans = 0;
        while (*min_element(r, r + 3) != n / 3)
        {
            for (int i = 0; i < 3; i++)
            {
                if (r[i] > n / 3)
                {
                    r[i]--;
                    r[(i + 1) % 3]++;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}