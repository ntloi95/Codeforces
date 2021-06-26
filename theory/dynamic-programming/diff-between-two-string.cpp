#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> diffBetweenTwoStrings(const string &src, const string &tar)
{
    int n = src.length();
    int m = tar.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (src[i - 1] == tar[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i - 1][j - 1] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    int i = 1;
    int j = 1;
    vector<string> ans;
    while (i <= n && j <= m)
    {
        string ch = "";

        if (src[i - 1] == tar[j - 1])
        {
            ch += src[i - 1];
            ans.push_back(ch);
            i++;
            j++;
        }
        else
        {
            if (i + 1 <= n && j + 1 <= m && dp[i + 1][j] <= dp[i][j + 1])
            {
                ch += "-";
                ch += src[i - 1];
                i++;
            }
            else
            {
                ch += "+";
                ch += tar[j - 1];
                j++;
            }

            ans.push_back(ch);
        }
    }

    for (; j <= m; j++)
    {
        ans.push_back(string(1, tar[j - 1]));
    }

    return ans;
}

int main()
{
    string a = "ABCDEFG";
    string b = "ABDFFGH";

    vector<string> c = diffBetweenTwoStrings(a, b);
    for (string x : c)
    {
        cout << x << endl;
    }
    return 0;
}
