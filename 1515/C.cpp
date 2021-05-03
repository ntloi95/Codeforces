#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define cgd __cgd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
vector<ii> v;

int sum(vi x)
{
    int sumX = 0;
    for (auto i : x)
    {
        sumX += v[i].first;
    }
    return sumX;
}

bool cmpSum(vi x, vi y)
{
    int sumX = sum(x);
    int sumY = sum(y);

    return sumX < sumY;
}

bool cmpVal(int x, int y)
{
    return v[x].first < v[y].first;
}

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n, m, x;
        cin >> n >> m >> x;
        v.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        vvi res(m, vi());

        int i = 0, j = n - 1;
        while (i <= j)
        {
            for (int k = 0; k < m && i <= j; k++)
            {
                res[k].push_back(i++);
            }

            for (int k = 0; k < m && i <= j; k++)
            {
                res[k].push_back(j--);
            }
        }

        while (1)
        {
            sort(res.begin(), res.end(), cmpSum);
            if (sum(res.back()) - sum(res.front()) > x)
            {
                sort(res.back().begin(), res.back().end(), cmpVal);
                res.front().push_back(res.back().back());
            }
            else
            {
                break;
            }
        }

        vi out(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                out[v[res[i][j]].second] = i + 1;
            }
        }

        cout << "YES" << el;
        for (auto a : out)
        {
            cout << a << ' ';
        }
        cout << el;
    }
    return 0;
}