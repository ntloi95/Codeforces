#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 200005;
int q[N], r[N];
bool v[N];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        memset(v, 0, sizeof(v));

        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
            v[q[i]] = true;
            r[i] = -1;
        }

        set<int> miss;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == false)
            {
                miss.insert(i);
            }
        }

        r[0] = q[0];

        for (int i = 1; i < n; i++)
        {
            if (q[i] != q[i - 1])
            {
                r[i] = q[i];
            }
        }

        auto it = miss.begin();
        for (int i = 0; i < n; i++)
        {
            if (r[i] != -1)
            {
                cout << r[i] << ' ';
            }
            else
            {
                cout << *it << ' ';
                it++;
            }
        }
        cout << endl;

        int pivot;
        for (int i = 0; i < n; i++)
        {
            if (r[i] != -1)
            {
                cout << r[i] << ' ';
                pivot = r[i];
            }
            else
            {
                it = miss.upper_bound(pivot);
                it--;
                cout << *it << ' ';
                miss.erase(it);
            }
        }
        cout << endl;
    }
    return 0;
}