#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200001;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }

        vector<int> h;
        for (auto x : cnt)
        {
            h.push_back(x.second);
        }

        sort(h.begin(), h.end());

        vector<int> sum(h.size(), 0);
        sum[0] = h[0];
        for (int i = 1; i < h.size(); i++)
        {
            sum[i] = sum[i - 1] + h[i];
        }

        map<int, int> last;
        for (int i = 0; i < h.size(); i++)
        {
            last[h[i]] = i;
        }

        int hLen = h.size();

        auto it = unique(h.begin(), h.end());
        h.resize(distance(h.begin(), it));
        int ans = sum[hLen - 1] - sum[last[h[0]]] - h[0] * (hLen - 1 - last[h[0]]);

        for (int i = 1; i < h.size(); i++)
        {
            int cur = sum[hLen - 1] - sum[last[h[i]]] - h[i] * (hLen - 1 - last[h[i]]) + sum[last[h[i - 1]]];
            ans = min(ans, cur);
        }

        cout << ans << endl;
    }
    return 0;
}