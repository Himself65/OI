#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 5;
int f[maxn], g[maxn];
int last[30], forbid[30][30];
char b[maxn];
int n, m;
int main()
{
    scanf("%d", &n);
    scanf("%s", b + 1);
    for (int i = 1; i <= n; i++)
        f[i] = b[i] - 'a';
    scanf("%d", &m);
    while (m--)
    {
        scanf("%s", b);
        forbid[b[0] - 'a'][b[1] - 'a'] = forbid[b[1] - 'a'][b[0] - 'a'] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        g[i] = 1;
        for (int j = 0; j < 26; j++)
            if (!forbid[j][f[i]])
                g[i] = max(g[i], last[j] + 1);
        last[f[i]] = max(last[f[i]], g[i]);
        ans = max(ans, g[i]);
    }
    printf("%d", n - ans);
    return 0;
}