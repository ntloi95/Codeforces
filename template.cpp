#include <bits/stdc++.h>
#include <chrono>
#define ll long long
using namespace std;
const int N = 50;
void solve()
{
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    solve();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Time = " << duration;
    return 0;
}