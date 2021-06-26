#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500;
int d[N];
int a[N];

void findRoot(int l, int r, int depth)
{
    if (l >= r)
    {
        return;
    }

    int maxID = l;
    int maxValue = a[l];
    for (int i = l + 1; i < r; i++)
    {
        if (a[i] > maxValue)
        {
            maxValue = a[i];
            maxID = i;
        }
    }

    d[maxID] = depth;

    findRoot(l, maxID, depth + 1);
    findRoot(maxID + 1, r, depth + 1);
}

int main()
{
    int nTest;
    cin >> nTest;

    while (nTest--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        findRoot(0, n, 0);

        for (int i = 0; i < n; i++)
        {
            cout << d[i] << ' ';
        }

        cout << endl;
    }

    return 0;
}