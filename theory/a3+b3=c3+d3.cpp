#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
using namespace std;
const int N = 10000;

int main()
{
    map<int, vii> m;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int x = i * i * i + j * j * j;

            if (m.count(x) == 0)
            {
                m[x] = vii(0);
            }

            m[x].push_back(ii(i, j));
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int x = i * i * i + j * j * j;

            if (m[x].size() > 1)
            {
                for (int it = 0; it < m[x].size(); it++)
                {
                    for (int jj = it + 1; jj < m[x].size(); jj++)
                    {
                        cout << m[x][it].fi << ' ' << m[x][it].se << " = " << m[x][jj].fi << ' ' << m[x][jj].se << endl;
                    }
                }
            }
        }
    }
    return 0;
}