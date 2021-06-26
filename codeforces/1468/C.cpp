#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;
int n, t, x;
set<ii> s2, s3;
int cnt = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        switch (t)
        {
        case 1:
        {
            cin >> x;
            cnt++;
            s2.insert(ii(cnt, x));
            s3.insert(ii(-x, cnt));
            break;
        }
        case 2:
        {
            auto v = s2.begin();
            cout << v->first << endl;
            s3.erase(ii(-v->second, v->first));
            s2.erase(v);
            break;
        }
        case 3:
        {
            auto v = s3.begin();
            cout << v->second << endl;
            s2.erase(ii(v->second, -v->first));
            s3.erase(v);
            break;
        }
        }
    }
    return 0;
}