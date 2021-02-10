#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;
int main()
{
    vector<ii> v;
    int n, cnt = 0;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int divisors = 0;
        while (n % i == 0)
        {
            divisors++;
            n /= i;
        }

        if (divisors)
        {
            v.push_back(ii(i, divisors));
        }
        cnt++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].fi;
        if (v[i].se != 1)
        {
            cout << '^' << v[i].se;
        }

        if (i != v.size() - 1)
        {
            cout << '.';
        }
    }
    cout << endl
         << cnt;
    return 0;
}