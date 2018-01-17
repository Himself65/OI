#include <cstdio>
#include <cstring>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
const int MAXN = 100010;
int a[MAXN];
int p[MAXN][32];
int n, q;

void init()
{
    for (int i = 1; i <= n; i++)
        p[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            p[i][j] = max(p[i][j - 1], p[i + (1 << j - 1)][j - 1]);
}
int query(int l, int r)
{
    int k = 0;
    while ((1 << k + 1) <= r - l + 1)
        k++;
    return max(p[l][k], p[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    init();
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}