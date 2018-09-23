#define LOCAL
#define TEST
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
const int maxn = 2e3 + 5;
int n, q;
char a[maxn][maxn];
int lx, ly, rx, ry;
inline void init(int x, int y)
{
    lx = x, rx = x, ry = y, ly = y;
}
inline bool check(int x, int y)
{
    if (lx < 1 || lx > n ||
        ly < 1 || ly > n ||
        rx < 1 || rx > n ||
        ry < 1 || ry > n)
        return false;
    if (a[lx][ly] == a[rx][ry])
        return true;
    return false;
}
inline int max(int a, int b) { return a > b ? a : b; }
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        cin >> a[i] + 1;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int ans1 = 1, ans2 = 1;
        init(x, y);
        lx--, rx++;
        while (check(x, y))
            lx--, rx++, ans1 += 2;
        init(x, y);
        ly--, ry++;
        while (check(x, y))
            ly--, ry++, ans2 += 2;
        printf("%d\n", max(ans1, ans2));
    }
#ifdef TEST
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
#endif
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