#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2000 + 5;
char a[maxn], b[maxn];
int k, len_a, len_b;
int f[maxn][maxn];
inline int min(int a, int b) { return a < b ? a : b; }
inline int min(int a, int b, int c) { return min(a, min(b, c)); }
inline int abs(int a) { return a >= 0 ? a : -a; }
int main()
{
    scanf(" %s", a + 1);
    scanf(" %s", b + 1);
    scanf("%d", &k);
    len_a = strlen(a + 1);
    len_b = strlen(b + 1);
    for (int i = 1; i <= len_a; i++)
        f[i][0] = f[i - 1][0] + k;
    for (int i = 1; i <= len_b; i++)
        f[0][i] = f[0][i - 1] + k;
    for (int i = 1; i <= len_a; i++)
        for (int j = 1; j <= len_b; j++)
            f[i][j] = min(f[i - 1][j] + k, f[i][j - 1] + k, f[i - 1][j - 1] + abs((int)(a[i] - b[j])));
    printf("%d", f[len_a][len_b]);
    return 0;
}