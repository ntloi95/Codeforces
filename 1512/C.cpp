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
const int N = 50;

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int a, b;
        string s;

        cin >> a >> b;
        cin >> s;

        int n = a + b;
        bool isNext = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '?')
            {
                int j = n - 1 - i;
                if (s[j] != '?')
                {
                    if (s[j] != s[i])
                    {
                        cout << -1 << endl;
                        isNext = true;
                        break;
                    }
                }
                else
                {
                    s[j] = s[i];
                }
            }
        }

        if (isNext)
            continue;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                a--;
            else if (s[i] == '1')
                b--;
        }

        if (a % 2 && b % 2)
        {
            cout << -1 << endl;
            continue;
        }
        else if ((a + b) % 2)
        {
            if (a % 2)
            {
                s[n / 2] = '0';
                a--;
            }
            else
            {
                s[n / 2] = '1';
                b--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                int j = n - 1 - i;
                if (a > 1)
                {
                    s[i] = s[j] = '0';
                    a -= 2;
                }
                else if (b > 1)
                {
                    s[i] = s[j] = '1';
                    b -= 2;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}