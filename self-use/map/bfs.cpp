#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #define LOCAl
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int n, m, t, fx, fy;
struct Node
{
    int x, y, step;
    bool wall, vis;
    Node() : wall(false), step(0), vis(false) {}
};
Node map[maxn][maxn];

ll ans = 0x7fffffff;
void bfs()
{
    queue<Node> q;
    q.push(map[fx][fy]);
    while (!q.empty())
    {
        Node &p = q.front();
        q.pop();
        if (p.wall)
            continue;
        else if (p.vis)
            continue;
        p.step++;
        for (int i = 0; i < 4; i++)
            q.push(map[p.x + dx[i]][p.y + dy[i]]);
    }
}

int main()
{
    INIT_CIN;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            map[i][j].x = i;
            map[i][j].y = j;
        }
    cin >> fx >> fy;
    while (t--)
    {
        int tx, ty;
        cin >> tx >> ty;
        map[tx][ty].wall = true;
    }
    bfs();
    cout << ans; //答案
    return 0;
}