#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 100005;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int cntEqual = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                cntEqual++;
            }
        }

        if (cntEqual)
        {
            if (cntEqual == n - 1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }

        int posDiff = -1;
        int negDiff = -1;

        bool isContinue = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1])
            {
                if (posDiff != -1 && a[i + 1] - a[i] != posDiff)
                {
                    cout << -1 << endl;
                    isContinue = true;
                    break;
                }

                if (posDiff == -1)
                {
                    posDiff = a[i + 1] - a[i];
                }
            }
            else
            {
                if (negDiff != -1 && a[i] - a[i + 1] != negDiff)
                {
                    cout << -1 << endl;
                    isContinue = true;
                    break;
                }

                if (negDiff == -1)
                {
                    negDiff = a[i] - a[i + 1];
                }
            }
        }

        if (isContinue)
        {
            continue;
        }

        if (posDiff == -1 || negDiff == -1)
        {
            cout << 0 << endl;
            continue;
        }

        int c = posDiff;
        int m = negDiff + c;

        if (m <= a[0])
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 1; i < n; i++)
        {
            if (a[i] != (a[i - 1] + c) % m)
            {
                isContinue = true;
                cout << -1 << endl;
                break;
            }
        }

        if (isContinue)
        {
            continue;
        }

        cout << m << ' ' << c << endl;
    }
    return 0;
}