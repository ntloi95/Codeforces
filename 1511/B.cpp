#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define el endl

#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 50;
const int MOD = 1e9 + 7;
ll prime[][2] = {
    {1, 2},
    {11, 13},
    {179, 191},
    {1009, 1019},
    {10007, 10009},
    {100003, 100019},
    {1000033, 1000081},
    {10000019, 10000169},
    {100000007, 100000049},
};

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int a, b, c;
        cin >> a >> b >> c;
        int newC = 1;
        for (int i = 0; i < c - 1; i++)
        {
            newC *= 10;
        }

        if (a == b)
        {
            cout << prime[a - c][0] * newC << ' ' << prime[a - c][1] * newC << endl;
        }
        else
        {
            cout << prime[a - c][0] * newC << ' ' << prime[b - c][0] * newC << endl;
        }
    }
    return 0;
}