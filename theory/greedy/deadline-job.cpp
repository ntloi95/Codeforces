#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 50;
struct job
{
    int id;
    int p;
    int d;

    bool operator=(const job b)
    {
        return id == b.id;
    }
};

bool cmpTime(job a, job b)
{
    return a.p < b.p;
}

bool operator<(const job a, const job b)
{
    return a.d < b.d;
}

bool check(job j, set<job> &doneJobs)
{
    int id = j.id;
    doneJobs.insert(j);

    int t = 0;

    for (auto i : doneJobs)
    {
        t += i.p;
        if (t > i.d)
        {
            doneJobs.erase(j);
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    job jobs[N];
    set<job> doneJobs;

    for (int i = 0; i < n; i++)
    {
        jobs[i].id = i;
        cin >> jobs[i].p;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].d;
    }

    sort(jobs, jobs + n, cmpTime);

    for (int i = 0; i < n; i++)
    {
        if (check(jobs[i], doneJobs))
        {
            doneJobs.insert(jobs[i]);
        }
    }

    int t = 0;
    for (auto i : doneJobs)
    {
        cout << "At " << t << " : " << i.id << ' ' << i.p << ' ' << i.d << endl;
        t += i.p;
    }

    for (int i = 0; i < n; i++)
    {
        if (!doneJobs.count(jobs[i]))
        {
            cout << jobs[i].id << endl;
        }
    }

    return 0;
}