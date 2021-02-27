#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

void generate(const string &s, vector<int> &ids, vector<bool> &v, int i, int &cnt)
{
    if (i == s.length())
    {
        cnt++;
        cout << cnt << ". ";

        for (int j = 0; j < s.length(); j++)
        {
            cout << s[ids[j]];
        }
        cout << endl;
    }

    for (int j = 0; j < s.length(); j++)
    {
        if (!v[j])
        {
            v[j] = true;
            ids[i] = j;
            generate(s, ids, v, i + 1, cnt);
            v[j] = false;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<bool> v(s.length(), false);
    vector<int> ids(s.length());

    int cnt = 0;
    generate(s, ids, v, 0, cnt);

    return 0;
}