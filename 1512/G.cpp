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

int divSum(int num)
{
    int res = 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == (num / i))
                res += i;
            else
                res += (i + num / i);
        }
    }

    return (res + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
    }
    return 0;
}