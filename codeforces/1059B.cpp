// #define LOCAL // For Windows
// #define TEST
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
const int maxn = 1e3 + 5;
int n, m;
char mp[maxn][maxn];
inline bool ck(int x, int y)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int px = x + i;
            int py = y + j;
            if (mp[px][py] == '.')
                return false; // cant
        }
    }
    return true;
}
inline bool check(int x, int y)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int px = x + i;
            int py = y + j;
            if (px > 1 && px < n && py > 1 && py < m)
            {
                if (ck(px, py)) // can
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c = getchar();
            while (c == '\n')
                c = getchar();
            mp[i][j] = c;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '#')
                if (check(i, j) == false)
                {
                    // cout << i << " " << j << endl;
                    printf("NO");
#ifdef LOCAL
                    system("pause");
#endif
                    return 0;
                }
        }
    printf("YES");
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;