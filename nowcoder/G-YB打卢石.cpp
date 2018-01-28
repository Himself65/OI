#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int a[200];
int f[200];
bool vis[200];
int n, l, r, mid;
bool dfs(int now, int cot)
{
    cot++;
    if (cot > 30)
    {
        return true;
    }
    else
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (a[i] < now)
                    continue;
                else
                {
                    vis[i] = true;
                    return dfs(a[i], cot + 1);
                }
            }
        }
    return false;
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    if (n < 30)
        cout << "no";
    else
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (dfs(-1000, 0))
            cout << "yes";
        else
            cout << "no";
    }
    return 0;
}