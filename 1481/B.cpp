#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;
int main()
{
    int nTest;
    cin >> nTest;

    while (nTest--)
    {
        int n, k, h[111];
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> h[i + 1];
        }

        int p;
        bool notFound = false;
        for (int i = 0; i < k; i++)
        {
            p = 1;
            while (p < n && h[p] >= h[p + 1])
            {
                p++;
            }

            if (p == n)
            {
                cout << "-1" << endl;
                notFound = true;
                break;
            }
            else
            {
                h[p]++;
            }
        }

        if (!notFound)
        {
            cout << p << endl;
        }
    }
    return 0;
}