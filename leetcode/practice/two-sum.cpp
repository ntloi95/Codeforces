#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define gcd __gcd

#define multitest \
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int32_t main()
{
    vector<int> nums;
    int max = 100001;
    int n = nums.size();
    int ans = 0;
    vector<int> cnt(max, 0);
    vector<int> prefix(max, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[nums[i]]++;
    }
    for (int i = 1; i < max; i++)
    {
        prefix[i] = prefix[i - 1] + cnt[i];
    }
    for (int i = 1; i <= max; i++)
    {
        for (int j = i; j <= max; j += i)
        {
            int X = prefix[j - 1];
            if (j > i)
            {
            } - prefix[j - i - 1]);
            ans += X * (j / i - 1) * cnt[i];
        }
    }

    return ans;
}