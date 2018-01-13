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
const int maxn = 16;
int n, ans = 0;
bool map[maxn][maxn];
bool vis[3][30]; // 开大一点
int C[maxn];
int t = 0;
inline void dfs(int cur)
{
    if (cur == n)
    {
        ans++;
    }
    else
        for (int i = 0; i < n; i++)
        {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
            {
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
                dfs(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
            }
        }
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}
