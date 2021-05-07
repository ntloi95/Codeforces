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
    int nTest;    \
    cin >> nTest; \
    while (nTest--)
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const int OPENPLUS = 1e9;
const int OPENPMIN = 1e9 + 1;

//"1+2+3+(4+5+(6-7))+10"
int cal(string s)
{
    stack<int> stack;
    string token = "";
    int n = s.size();
    string op = "+";
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            token += s[i];
        }
        else
        {
            if (token != "")
            {
                token = op + token;
                stack.push(stoi(token));
                token = "";
            }

            if (s[i] == '+' || s[i] == '-')
            {
                op = s[i];
            }
            else if (s[i] == '(')
            {
                if (op == "+")
                {
                    stack.push(OPENPLUS);
                }
                else
                {
                    stack.push(OPENPMIN);
                }
                op = "+";
            }
            else
            {
                int sum = 0;
                int ele;

                while (1)
                {
                    ele = stack.top();
                    stack.pop();

                    if (ele == OPENPMIN || ele == OPENPLUS)
                    {
                        break;
                    }

                    sum += ele;
                }

                if (ele == OPENPMIN)
                {
                    sum = -sum;
                }
                stack.push(sum);
            }
        }
    }

    if (token != "")
    {
        token = op + token;
        stack.push(stoi(token));
    }

    int ans = 0;
    while (!stack.empty())
    {
        int ele = stack.top();
        stack.pop();
        ans += ele;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    string s = "1+2+3+((4+5-(6-7))+10)"; // 24
    cout << cal(s);
    return 0;
}