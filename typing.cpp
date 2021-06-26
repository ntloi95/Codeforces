#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int x = 3;

    cout << binary_search(v.begin(), v.end(), x);
}