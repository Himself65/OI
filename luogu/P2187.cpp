#include <cstdio>
const int maxn = 100000 + 5;
int f[maxn], g[maxn];
int last[30], cantnear[30][30];
char b[maxn];
int n, m, ans = 0;
inline int max(int a, int b) { return a > b ? a : b; }
int main()
{
    scanf("%d", &n);
    scanf("%s ", b + 1);
    for (int i = 1; i <= n; i++)
        f[i] = b[i] - 'a';
    scanf("%d", &m);
    while (m--)
    {
        char x, y;
        scanf(" %c%c", &x, &y);
        cantnear[x - 'a'][y - 'a'] = cantnear[y - 'a'][x - 'a'] = 1;
    } // 输入
    // DP
    for (int i = 1; i <= n; i++)
    {
        g[i] = 1;
        for (int j = 0; j < 26; j++)
            if (!cantnear[j][f[i]]) // 如果这两个字符可以靠近
                g[i] = max(g[i], last[j] + 1);  // 维护最大保留数
        last[f[i]] = max(last[f[i]], g[i]);
        ans = max(ans, g[i]);
    }
    printf("%d", n - ans);
    return 0;
}