#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;
const int oo = 100000;
int n;
int a[N][N];
bool visited[N];
int curPath[N];
int bestPath[N];
int bestDistance = oo;

void recursiveFind(int x, int currentDistance, int cnt)
{
    curPath[cnt - 1] = x;
    if (cnt == n && currentDistance + a[x][0] < bestDistance)
    {
        bestDistance = currentDistance + a[x][0];
        for (int i = 0; i < n; i++)
        {
            bestPath[i] = curPath[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (x != i && !visited[i] && currentDistance + a[i][x] < bestDistance)
        {
            visited[i] = true;
            recursiveFind(i, currentDistance + a[i][x], cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    visited[0] = true;
    recursiveFind(0, 0, 1);

    cout << bestDistance << endl;
    for (int i = 0; i < n; i++)
    {
        cout << bestPath[i] << ' ';
    }
    return 0;
}