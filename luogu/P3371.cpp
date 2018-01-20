#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
using namespace std;
struct node
{
    int x;
    int y;
    int c;
    int next;
} edge[500001];
int last[10001], len = 0, dis[100010], s, n, m;
bool vis[10001];
queue<int> q;
inline int read()
{
    int res = 0, flag = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
    return res * flag;
}
inline void add(int x, int y, int c)
{
    edge[++len].x = x, edge[len].y = y, edge[len].c = c;
    edge[len].next = last[x];
    last[x] = len;
}
void spfa()
{
    for (int i = 1; i <= n; i++)
        dis[i] = 2147483647;
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int k = last[x]; k; k = edge[k].next)
        {
            int y = edge[k].y;
            if (dis[y] > dis[x] + edge[k].c)
            {
                dis[y] = dis[x] + edge[k].c;
                if (!vis[y])
                    vis[y] = 1, q.push(y);
            }
        }
    }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read(), c = read();
        add(x, y, c);
    }
    spfa();
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
}