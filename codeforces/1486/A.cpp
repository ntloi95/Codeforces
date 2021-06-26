#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
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

        ll sum = 0, need = 0;
        ll x;

        bool yes = true;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            sum += x;
            need += i;

            if (sum < need)
            {
                for (i = i + 1; i < n; i++)
                {
                    cin >> x;
                }
                cout << "NO" << endl;
                yes = false;
            }
        }

        if (yes)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}