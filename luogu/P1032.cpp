#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
string s, e;
map<string, int> Has;
string a[11], b[11];
int la[11], lb[11];
int n = 1;
int mx = 0, mn = 0;
void dfs(string x, int step)
{
    if (step >= 10)
        return;
    int v = x.size(), p = e.size();
    if (v + mx * (10 - step) < p)
        return;
    if (v + mn * (10 - step) > p)
        return;
    step++;
    for (int i = 1; i <= n; i++)
    {
        int pos = x.find(a[i], 0);
        while (pos != string::npos)
        {
            string tmp = x;
            tmp.replace(pos, la[i], b[i]);
            if ((Has[tmp] == 0 && tmp != s) || Has[tmp] > Has[x] + 1)
                Has[tmp] = Has[x] + 1, dfs(tmp, step);
            pos = x.find(a[i], pos + 1);
        }
    }
}
int main()
{
    cin >> s >> e;
    while (cin >> a[n] >> b[n])
    {
        la[n] = a[n].size();
        lb[n] = b[n].size();
        mn = min(mn, lb[n] - la[n]);
        mx = max(mx, lb[n] - la[n]);
        n++;
        if (n == 7)
            break;
    }
    n--;
    dfs(s, 0);
    if (Has[e] != 0)
        cout << Has[e];
    else
        cout << "NO ANSWER!";
}