#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> v;

    FenwickTree(int n) {
        v = vector<int>(n+1, 0);
    }

    void add(int x) {
        for (int i = x; i < v.size(); i += i&-i) {
            v[i]++;
        }
    }

    int get(int x) {
        int ans;
        for (int i = x; i > 0; i -= i&-i) {
            ans += v[i];
        }

        return ans;
    }
};


int inversionCount(vector<int> v) {
    int n = v.size();
    int maxVal = *max_element(v.begin(), v.end());
    FenwickTree f(maxVal);
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        ans += f.get(v[i]-1);
        f.add(v[i]);
    }

    return ans;
}

int main()
{
    vector<int> v({ 1, 9, 6, 4, 5});
    cout << inversionCount(v);    

    return 0;
}