#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;

void output(int x[], int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << x[i] << ' ';
    }
    cout << endl;
}

void combination(int x[], int i, int n, int k)
{
    for (int j = x[i - 1] + 1; j <= n + k - i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            output(x, k);
        }
        else
        {
            combination(x, i + 1, n, k);
        }
    }
}

int main()
{
    int n, k, x[N] = {0};
    cin >> n >> k;

    combination(x, 1, n, k);
    return 0;
}