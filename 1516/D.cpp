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

vector<int> findArrayQuadruplet(const vector<int> &arr, int s)
{
    // your code goes here
    int n = arr.size();
    if (n < 4)
    {
        vector<int> empty;
        return empty;
    }

    vector<int> a = arr;
    sort(a.begin(), a.end()); // 4, 4, 4, 4

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int r = s - a[i] - a[j]; // 16 - 4 - 4 = 8
            int l = j + 1;           // 2
            int h = n - 1;           // 3
            while (l < h)
            {
                if (a[l] + a[h] < r)
                {
                    l++;
                }
                else if (a[l] + a[r] > r)
                {
                    h--;
                }
                else
                {
                    cout << "Why don't you return here?" << endl;
                    vector<int> res(4);
                    res[0] = a[i];
                    res[1] = a[j];
                    res[2] = a[l];
                    res[3] = a[h];

                    return res;
                }
            }
        }
    }

    vector<int> empty;
    return empty;
}

int main()
{
    vector<int> v({4, 4, 4, 4});
    auto res = findArrayQuadruplet(v, 16);

    for (int x : res)
    {
        cout << x << ' ';
    }
    return 0;
}