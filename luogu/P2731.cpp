#define LOCAL
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 1024 + 5;
int n, mx, mi, st = 1, ctp;
int G[maxn][maxn], angle[maxn], a[maxn];
stack<int> s;
inline void f(int i)
{
    for (register int j = mi; j <= mx; ++j)
    {
        if (G[i][j])
        {
            G[i][j]--, G[j][i]--;
            f(j);
        }
    }
    a[++ctp] = i;
}
int main()
{
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ++G[x][y], ++G[y][x];
        ++angle[x], ++angle[y];
        mx = max(mx, max(x, y));
        mi = min(mi, min(x, y));
    }
    for (register int i = mi; i <= mx; ++i)
    {
        if (angle[i] % 2) // 找开始点
        {
            st = i;
            break;
        }
    }
    f(st);
    for (register int i = ctp; i >= 1; --i)
        printf("%d\n", a[i]); // 模拟栈
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}