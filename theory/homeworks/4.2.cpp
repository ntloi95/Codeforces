#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

void generate(int ans[], int i, int n)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << endl;
        return;
    }

    for (int j = 0; j <= 1; j++)
    {
        ans[i] = j;
        generate(ans, i + 1, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int ans[N];
    generate(ans, 0, n);
    return 0;
}