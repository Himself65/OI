#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
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
int mp[6][6];
bool temp[6][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int total, fx, fy, sx, sy, T, n, m, l, r;
void dfs(int x, int y)
{
    if (x == fx && y == fy)
        total++;
    else
        for (int i = 0; i <= 3; i++)
        {
            if (temp[x + dx[i]][y + dy[i]] == 0 && mp[x + dx[i]][y + dy[i]] == 1)
            {
                temp[x][y] = 1;
                dfs(x + dx[i], y + dy[i]);
                temp[x][y] = 0;
            }
        }
}
int main()
{
    INIT_CIN;
    cin >> n >> m >> T;
    for (int ix = 1; ix <= n; ix++)
        for (int iy = 1; iy <= m; iy++)
            mp[ix][iy] = 1;
    cin >> sx >> sy;
    cin >> fx >> fy;
    for (int u = 1; u <= T; u++)
    {
        cin >> l >> r;
        mp[l][r] = 0;
    }
    dfs(sx, sy);
    cout << total;
    return 0;
}