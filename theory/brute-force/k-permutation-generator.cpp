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

void kPermutation(int x[], int i, int d[], int k, int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (!d[j])
        {
            x[i] = j;
            d[j] = 1;

            if (i == k)
            {
                output(x, k);
            }
            else
            {
                kPermutation(x, i + 1, d, k, n);
            }
            d[j] = 0;
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    int x[N] = {0}, d[N] = {0};
    kPermutation(x, 1, d, k, n);
    return 0;
}