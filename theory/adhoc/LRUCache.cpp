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

class LRUCache
{
public:
    int _size;
    map<string, pair<string, int>> hash;
    map<int, string> priority;

    LRUCache(int size)
    {
        _size = size;
    }

    void set(string key, string value)
    {
        if (hash.size() >= _size)
        {
            auto oldest = priority.begin();
            auto oldest_key = oldest->second;
            auto oldest_priority = oldest->first;

            hash.erase(oldest_key);
            priority.erase(oldest_priority);
        }

        int new_priority = priority.size() == 0 ? 0 : priority.rbegin()->first + 1;
        hash[key] = {value, new_priority};
        priority[new_priority] = key;
    }

    string get(string key)
    {
        if (hash.count(key) == 0)
        {
            return "";
        }

        auto node = hash[key];
        int new_priority = priority.rbegin()->first + 1;
        int old_priority = node.second;
        priority.erase(old_priority);
        priority[new_priority] = key;

        hash[key] = {node.first, new_priority};

        return node.first;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    LRUCache cache(3);
    cache.set("a", "1");
    cache.set("b", "2");
    cache.set("c", "3");

    cout << cache.get("a") << endl;
    cout << cache.get("b") << endl;
    cout << cache.get("c") << endl;
    cout << cache.get("d") << endl;

    cache.set("d", "4");
    cout << cache.get("a") << endl;
    cout << cache.get("d") << endl;

    return 0;
}