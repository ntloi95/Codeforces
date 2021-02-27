#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 50;

void output(int resIDs[], const string names[], int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << names[resIDs[i] - 1] << ' ';
    }

    cout << endl;
}

void generateCombination(int resIDs[], const string names[], int i, int n, int k)
{
    if (i > k)
    {
        output(resIDs, names, k);
        return;
    }

    for (int j = resIDs[i - 1] + 1; j <= n - k + i; j++)
    {
        resIDs[i] = j;
        generateCombination(resIDs, names, i + 1, n, k);
    }
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    string names[N];
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    int resIDs[N] = {0};
    generateCombination(resIDs, names, 1, n, k);

    return 0;
}