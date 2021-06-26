#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 200005;

int res[N];

void printRes(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (res[i] == 1)
        {
            cout << ')';
        }
        else
        {
            cout << '(';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (s[0] != '1' || s[n - 1] != '1')
        {
            cout << "NO" << endl;
            continue;
        }

        res[0] = 0;
        res[n - 1] = 1;

        int cnt = 0;
        int c = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '1')
            {
                res[i] = c;
                c = 1 - c;
                cnt++;
            }
        }

        if (cnt % 2)
        {
            cout << "NO" << endl;
            continue;
        }

        c = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                res[i] = c;
                c = 1 - c;
            }
        }
        cout << "YES" << endl;
        printRes(n);
        cout << endl;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                res[i] = 1 - res[i];
            }
        }
        printRes(n);
        cout << endl;
    }
    return 0;
}