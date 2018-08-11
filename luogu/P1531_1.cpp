#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 200000 + 5;
int n, m;
int a[maxn], f[maxn];
#define LOWBIT(x) (x & (-x))
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline void update(int x, int val)
{
    while (x <= n)
    {
        f[x] = max(f[x], val);
        x += LOWBIT(x);
    }
}
inline int getMax(int l, int r)
{
    int ans = 0;
    while (l <= r)
    {
        while (r - LOWBIT(r) >= l)
        {
            ans = max(f[r], ans);
            r -= LOWBIT(r);
        }
        ans = max(a[r], ans);
        r--;
    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), update(i, a[i]);
    for (int i = 1; i <= m; i++)
    {
        char op;
        cin >> op;
        int x, y;
        scanf("%d%d", &x, &y);
        if (op == 'Q')
            printf("%d\n", getMax(x, y));
        else
        {
            a[x] = max(a[x], y);
            update(x, a[x]);
        }
    }
    system("pause");
    return 0;
}