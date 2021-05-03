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

const int ENTERED = 1;
const int VISITED = 2;
const int NOTVISITED = 0;

vi edges[N];
int status[N];

bool dfs(int v, int n, vector<int> &res)
{
    if (ENTERED == status[v]) // v = 3
    {
        return false;
    }

    if (VISITED == status[v])
    {
        return true;
    }

    status[v] = ENTERED; // status[0] = 1, [1] = 1, [2] = 1, [3] = 1
    for (int i = 0; i < edges[v].size(); i++)
    {
        if (!dfs(edges[v][i], n, res))
        {
            return false;
        }
    }

    res.push_back(v);
    status[v] = VISITED;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[0].push_back(3);
    edges[3].push_back(0);
    edges[1].push_back(2);
    edges[2].push_back(3);
    edges[3].push_back(4);
    int n = 6;

    // res 4, 3, 2, 1, 0
    fill(status, status + n, NOTVISITED);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (NOTVISITED == status[i])
        {
            bool ok = dfs(i, n, res);
            if (!ok)
            {
                cout << -1;
                return 0;
            }
        }
    }

    for (int x : res)
    {
        cout << x << ' ';
    }
    return 0;
}
