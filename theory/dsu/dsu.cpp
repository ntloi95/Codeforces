#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;

int par[N];

int root(int v)
{
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void merge(int x, int y) // x = 1, y = 2
{
    if ((x = root(x)) == (y = root(y)))
    {
        return;
    }

    if (par[x] > par[y])
    {
        swap(x, y);
    }

    par[x] += par[y]; // par[1] = -2
    par[y] = x;       // par[2] = 1
}