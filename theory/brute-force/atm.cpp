#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;

void output(int x[], int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        if (x[i])
        {
            cout << a[i] << ' ';
        }
    }
    cout << endl;
}

void atm(int x[], int i, int n, int a[], int sum, int cur)
{
    if (cur == sum)
    {
        output(x, n, a);
        return;
    }

    if (i >= n)
    {
        return;
    }

    x[i] = 1;
    cur += a[i];
    atm(x, i + 1, n, a, sum, cur);

    x[i] = 0;
    cur -= a[i];
    atm(x, i + 1, n, a, sum, cur);
}

int main()
{
    int x[N] = {0}, a[N], sum = 0, cur = 0, n;
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    atm(x, 0, n, a, sum, cur);
    return 0;
}