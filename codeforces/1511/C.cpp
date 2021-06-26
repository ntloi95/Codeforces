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

int main()
{
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    list<int> l;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }

    for (int j = 0; j < q; j++)
    {
        int t;
        cin >> t;
        int id = 1;
        auto p = l.begin();

        while (*p != t)
        {
            id++;
            p++;
        }
        cout << id << ' ';
        l.erase(p);
        l.push_front(t);
    }
    return 0;
}