#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define gcd __gcd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 5e3 + 10;
const int MOD = 1e9 + 7;

int n, k, m;
vi full_path[N];
int n_path_full;
vi e[N];
int w[N];
vi q;
vvi region;
bool used[N];
bool marked[N];

void map_single_point()
{
    vvi tmp_region;
    for (int u : e[1])
    {
        vi tmp;
        while (e[u].size() == 1)
        {
            tmp.push_back(u);
            u = e[u][0];
        }

        if (u == n && tmp.size() > 0)
        {
            tmp_region.push_back(tmp);
        }
    }

    for (auto &val : tmp_region)
    {
        region.push_back(val);
        bool has_marked = false;
        for (auto x : val)
        {
            used[x] = true;
            if (marked[x])
            {
                has_marked = true;
            }
            marked[x] = true;
        }

        if (!has_marked)
        {
            q.push_back(val[0]);
        }
    }
}

/*
void dfs(int u, int path_id = 1)
{
    n_path_full = max(n_path_full, path_id);

    if (e[u].size() == 0)
    {
        full_path[u].push_back(path_id);
        // return 1;
        return;
    }

    int sum = 0;
    if (e[u].size() > 1)
    {
        return;
    }

    for (auto v : e[u])
    {
        dfs(v, path_id);
        int sz = 1;
        path_id += sz;

        for (int i = 0; i < sz; i++)
        {
            full_path[u].push_back(
                full_path[v][full_path[v].size() + i - sz]);
        }

        sum += sz;
    }

    return;
} */

void input()
{
    n_path_full = 0;
    q.clear();
    region.clear();

    cin >> n;
    fill(used, used + n + 10, false);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        full_path[i].clear();
        e[i].clear();
    }

    fill(marked, marked + n + 10, false);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        marked[x] = true;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        input();
        // dfs(1);
        map_single_point();

        // cal additional marked points
        if (!marked[1] && !marked[n])
        {
            q.push_back(1);
        }

        for (int i = 2; i < n; i++)
        {
            if (!marked[i])
            {
                q.push_back(i);
            }
        }

        // print marked points
        cout << q.size() << ' ';
        for (int x : q)
        {
            cout << x << ' ';
        }
        cout << endl;

        // cal region
        region.push_back(vi({1, n}));
        for (int i = 2; i < n; i++)
        {
            if (!used[i])
                region.push_back(vi({i}));
        }

        cout << region.size() << endl;
        // print region
        for (auto &r : region)
        {
            cout << r.size() << ' ';
            for (auto x : r)
            {
                cout << x << ' ';
            }

            cout << endl;
        }
    }
    return 0;
}