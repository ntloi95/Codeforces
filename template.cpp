#include <bits/stdc++.h>
#define ll long long
#define ld double
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define el endl
#define bit1 __builtin_popcount
#define less_bit_1 __builtin_ctz
#define cgd __cgd

#define multitest \
    int t;        \
    cin >> t;     \
    while (t--)
using namespace std;
const int N = 50;
const int MOD = 1e9 + 7;

bool isBalance(vector<int> &cntLower, vector<int> &cntUpper)
{
    for (int i = 0; i < 26; i++)
    {
        if (cntLower[i] && cntUpper[i] == 0)
        {
            return false;
        }
        else if (cntLower[i] == 0 && cntUpper[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    string s = "Technocat";
    int n = s.size();
    vector<int> cntLower(26, 0);
    vector<int> cntUpper(26, 0);

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            cntLower[s[i] - 'a']++; // {a: 4, b: 2, z: 1}
        }
        else
        {
            cntUpper[s[i] - 'A']++; // {A: 1, B: 1}
        }
    }

    set<char> invalid; // z
    for (int i = 0; i < 26; i++)
    {
        if (cntLower[i] && cntUpper[i] == 0)
        {
            invalid.insert(i + 'a');
        }
        else if (cntLower[i] == 0 && cntUpper[i])
        {
            invalid.insert(i + 'A');
        }
    }

    int start = 0;
    fill(cntLower.begin(), cntLower.end(), 0);
    fill(cntUpper.begin(), cntUpper.end(), 0);
    int ans = n + 1;

    // azABaabba
    for (int i = 0; i < n; i++)
    {
        if (invalid.count(s[i])) //
        {
            start = i + 1; // 2
            fill(cntLower.begin(), cntLower.end(), 0);
            fill(cntUpper.begin(), cntUpper.end(), 0);
            continue;
        }

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            cntLower[s[i] - 'a']++; // {a: 2, b: 1}
        }
        else
        {
            cntUpper[s[i] - 'A']++; // {A: 1, B: 1}
        }

        if (isBalance(cntLower, cntUpper))
        {
            while (1)
            {
                if (s[start] >= 'a' && s[start] <= 'z' && cntLower[s[start] - 'a'] > 1)
                {
                    cntLower[s[start] - 'a']--;
                    start++;
                }
                else if (s[start] >= 'A' && s[start] <= 'A' && cntUpper[s[start] - 'A'] > 1)
                {
                    cntUpper[s[start] - 'A']--;
                    start++;
                }
                else
                {
                    break;
                }
            }

            ans = min(ans, i - start + 1); // 6-2+1 = 5
            if (s[start] >= 'a' && s[start] <= 'z')
            {
                cntLower[s[start] - 'a']--;
            }
            else
            {
                cntUpper[s[start] - 'A']--;
            }
            start++;
        }
    }

    if (ans == (n + 1))
        cout << -1;
    else
        cout << ans;
    return 0;
}

/*
az
Baabba
*/