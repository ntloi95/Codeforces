#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

int fen[N];
int a[N];
int n;

void update(int p, int val)
{
    for (int i = p; i <= n; i += i & -i)
        fen[i] += val;
}

int sumFrom1To(int p)
{
    int ans = 0;
    for (int i = p; i; i -= i & -i)
        ans += fen[i];
    return ans;
}

int sumFromIToJ(int i, int j)
{
    int ans = 0;

    while (j >= i)
    {
        if (j - (j & -j) >= i)
        {
            ans += fen[j];
            j -= j & -j;
        }
        else
        {
            ans += a[j];
            j--;
        }
    }

    return ans;
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        cout << (i & -i) << endl;
    }
    return 0;
}