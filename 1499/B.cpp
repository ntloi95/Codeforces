#include <bits/stdc++.h>
#define ll long long
#define ld double
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
    multitest
    {
        string s;
        cin >> s;

        auto pos = s.find("11");
        if (s.find("00", pos) != string::npos)
        {
            cout << "NO" << el;
        }
        else
        {
            cout << "YES" << el;
        }
    }
    return 0;
}