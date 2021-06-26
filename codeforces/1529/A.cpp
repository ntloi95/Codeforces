#include <bits/stdc++.h>

using namespace std;
// I can hear your mom's voice.
// May be that make you offline.
// Take care, mate.
//
bool hasEdge(const string &a, const string &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            diff++;
            if (diff > 1)
            {
                return false;
            }
        }
    }

    return diff == 1;
}

int shortestWordEditPath(const string &source, const string &target, const vector<string> &words)
{
    int n = words.size(); // N+2 vertexes
    vector<vector<int>> edge(n + 1, vector<int>());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (hasEdge(words[i], words[j]))
            {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (hasEdge(words[i], source))
        {
            edge[n].push_back(i);
            edge[i].push_back(n);
        }
    }

    queue<int> q;
    q.push(n);
    vector<bool> visit(n + 1, false);
    vector<int> step(n + 1, 0);
    step[n] = 0;
    visit[n] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i : edge[u])
        {
            if (!visit[i])
            {
                if (words[i] == target)
                {
                    return step[u] + 1;
                }

                q.push(i);
                visit[i] = true;
                step[i] = step[u] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<string> words = {"but", "put", "big", "pot", "pog", "dog", "lot"};
    string source = "bit", target = "dog";
    cout << shortestWordEditPath(source, target, words);

    return 0;
}
/*
*/