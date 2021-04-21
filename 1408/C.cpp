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
double l;
vector<int> a;

double x1(double t)
{
    double v = 1;
    double x = 0;
    for (int i = 0; i < a.size(); i++)
    {
        double dt = (a[i] - x) / v;

        if (dt > t)
        {
            return min(x + v * t, l);
        }

        v++;
        x = a[i];
        t -= dt;
    }

    return min(x + v * t, l);
}

double x2(double t)
{
    double v = 1;
    double x = l;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        double dt = (x - a[i]) / v;

        if (dt > t)
        {
            return max(x - v * t, 0.0);
        }

        v++;
        x = a[i];
        t -= dt;
    }

    return max(x - v * t, 0.0);
}

int main()
{
    ios::sync_with_stdio(false);
    multitest
    {
        int n;
        cin >> n >> l;
        a.resize(n);
        for (int &x : a)
        {
            cin >> x;
        }

        double left = 0;
        double right = l;
        double mid = (left + right) / 2;
        while (right - left > 0.0000001)
        {
            double c1 = x1(mid);
            double c2 = x2(mid);

            if (c1 < c2)
            {
                left = mid;
            }
            else if (c1 > c2)
            {
                right = mid;
            }
            else
                break;
            mid = (left + right) / 2;
        }

        cout << fixed << setprecision(10) << mid << endl;
    }
    return 0;
}