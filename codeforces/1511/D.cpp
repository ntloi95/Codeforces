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
    int n, k;
    cin >> n >> k;
    string s = "a";
    int mx[26] = {0};
    int next = 'a';
    for (int i = 0; i < k * k - 1; i++)
    {
        int len = s.length();
        int pos = s[len - 1] - 'a';
        int c = mx[pos] + 'a';
        while (mx[c - 'a'] == k)
        {
            c++;
        }
        s += char(c);
        mx[pos]++;
    }

    for(int i = 0; i < n; i++) {
        cout << s[i % s.length()];
    }
    return 0;
}
