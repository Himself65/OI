#define LOCAL
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
typedef long long ll;
const int maxn = 1e+6 + 5;
int n, m, a[maxn], f[maxn];
struct Node
{
    int d, l, r;
} node[maxn];
inline bool check(int x)
{
    // 前缀和
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= x; i++)
    {
        Node &t = node[i];
        f[t.l] += t.d;
        f[t.r + 1] -= t.d;
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
        // 需要的教室大于已有的教室
        if (f[i] > a[i])
            return true;
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &node[i].d, &node[i].l, &node[i].r);
    int l = 1, r = m, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (m != r)
        cout << "-1\n"
             << r;
    else
        cout << 0;
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}