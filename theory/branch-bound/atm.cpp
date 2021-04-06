#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;
const int oo = 10000;
int n, s, a[N];
int bestCnt = oo;
bool bestSolution[N];
bool curSolution[N];
int maxValues[N];

void recursiveFind(int x, int curSum, int curCnt)
{
    if (curSum == s && bestCnt > curCnt)
    {
        bestCnt = curCnt;
        memcpy(bestSolution, curSolution, sizeof(curSolution));
    }

    if (curSum >= s || curCnt >= bestCnt || x == n || curCnt + (s - curSum) / (maxValues[x]) >= bestCnt)
    {
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        curSolution[x] = i;
        recursiveFind(x + 1, curSum + i * a[x], curCnt + i);
    }
}

void solve()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    maxValues[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxValues[i] = max(maxValues[i + 1], a[i]);
    }

    recursiveFind(0, 0, 0);

    cout << bestCnt << endl;
    for (int i = 0; i < n; i++)
    {
        if (bestSolution[i])
        {
            cout << a[i] << ' ';
        }
    }
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    solve();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << endl
              << "Time (microseconds) = " << duration;
    return 0;
}