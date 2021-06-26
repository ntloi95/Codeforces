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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (n < k + 1 || (n % 2) != ((k + 1) % 2))
        {
            cout << "NO" << el;
            continue;
        }

        bool isContinue = false;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
            {
                cout << "NO" << el;
                isContinue = true;
                break;
            }
        }

        if (isContinue)
        {
            continue;
        }

        cout << "YES";
    }
    return 0;
}