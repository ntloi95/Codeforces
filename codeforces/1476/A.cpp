#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        long long n, k;
        cin >> n >> k;

        if (k < n)
        {
            k = (n + k - 1) / k * k;
        }

        cout << (k + n - 1) / n << endl;
    }
    return 0;
}