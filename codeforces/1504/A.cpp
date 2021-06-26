#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

bool palin(string s)
{
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> s;
        n = s.length();

        string s1 = "a" + s;
        string s2 = s + "a";

        if (palin(s1) == false)
        {
            cout << "YES" << endl
                 << s1 << endl;
        }
        else if (palin(s2) == false)
        {
            cout << "YES" << endl
                 << s2 << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}