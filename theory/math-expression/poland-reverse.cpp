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

bool isOperator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

bool isLessPriority(char c1, char c2)
{
    map<char, int> priority;
    priority['+'] = priority['-'] = 0;
    priority['*'] = priority['/'] = 1;

    return priority[c1] < priority[c2];
}

// "1+2+3+(4+5-(6-7))+10"
vector<string> revertPolishNotation(string s)
{
    vector<string> t;      // t = 1 2 + 3 + 4 5 + 6 7 - - 10 + +
    stack<char> functions; // + +
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            string num;
            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                i++;
            }
            i--;
            t.push_back(num);
        }
        else if (isOperator(s[i]))
        {
            while (!functions.empty())
            {
                char op = functions.top();
                if (!isOperator(op) || isLessPriority(op, s[i]))
                {
                    break;
                }

                t.push_back(string(1, op));
                functions.pop();
            }
            functions.push(s[i]);
        }
        else if (s[i] == '(')
        {
            functions.push(s[i]);
        }
        else
        {
            while (!functions.empty())
            {
                char op = functions.top();
                functions.pop();
                if (op == '(')
                {
                    break;
                }
                t.push_back(string(1, op));
            }
        }
    }

    while (!functions.empty())
    {
        char op = functions.top();
        functions.pop();
        t.push_back(string(1, op));
    }

    return t;
}

int calculate(vector<string> t)
{
    int n = t.size();
    stack<int> numbers; // 26

    // 1 2 + 3 + 4 5 + 6 7 - - + 10 +
    for (auto x : t)
    {
        if (isOperator(x[0]))
        {
            int num1 = numbers.top();
            numbers.pop();
            int num2 = numbers.top();
            numbers.pop();

            switch (x[0])
            {
            case '+':
                numbers.push(num1 + num2);
                break;
            case '-':
                numbers.push(num2 - num1);
                break;
            case '*':
                numbers.push(num1 * num2);
                break;
            case '/':
                numbers.push(num2 / num1);
                break;
            }
        }
        else
        {
            numbers.push(stoi(x));
        }
    }

    return numbers.top();
}

int main()
{
    ios::sync_with_stdio(false);
    string s = "1*2+3*4-5*6-(3-2-1-10)"; // 26 // 1*2+1-2*3*4
    vector<string> t = revertPolishNotation(s);

    for (auto x : t)
    {
        cout << x << ' ';
    }

    cout << endl
         << calculate(t);

    return 0;
}