#include <cstdio>
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int x, ans = 0, maxa = 0, maxsofar = 0, n, t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%d %d", &maxa, &maxsofar);
        ans = maxa - maxsofar;
        for (register int i = 2; i < n; i++)
        {
            scanf("%d", &x);
            ans = max(ans, maxa - x);
            maxa = max(maxa, x);
        }
        printf("%d\n", ans);
    }
    return 0;
}