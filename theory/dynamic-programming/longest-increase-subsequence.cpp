#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
using namespace std;
const int N = 50;

int my_lower_bound(vector<int> f, int v)
{
    int l = 0;
    int r = f.size();
    while (l < r)
    {
        int m = (l + r) / 2;
        if (f[m] < v)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return r;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15});
    vi f;
    vi end_id;
    vi trace(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        auto j = my_lower_bound(f, x);
        if (j == f.size())
        {
            trace[i] = end_id.empty() ? -1 : end_id.back();
            f.push_back(x);
            end_id.push_back(i);
        }
        else
        {
            f[j] = x;
            if (j == 0)
            {
                trace[i] = -1;
            }
            else
            {
                trace[i] = end_id[j - 1];
            }
            end_id[j] = i;
        }
    }

    vector<int> ans;
    int id = end_id.back();
    while (id != -1)
    {
        ans.push_back(a[id]);
        id = trace[id];
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans)
    {
        cout << x << ' ';
    }
    return 0;
}