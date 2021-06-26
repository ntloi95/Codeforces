#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 105;
int m[N][N];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < b.length(); j++)
            {
                for (int k = 0; k < min(a.length() - i, b.length() - j); k++)
                {
                    if (a[i + k] != b[j + k])
                    {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}