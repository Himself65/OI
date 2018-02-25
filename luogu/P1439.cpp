#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100000 + 5;
int a1[maxn], a2[maxn], b[maxn], map[maxn], f[maxn], n, len;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a1[i]);
        map[a1[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a2[i]);
    for (int i = 1; i <= n; i++)
    {
        if (map[a2[i]] > b[len])
        {
            b[++len] = map[a2[i]];
            f[i] = len;
        }
        else
        {
            int k = lower_bound(b + 1, b + 1 + len, map[a2[i]]) - b;
            b[k] = map[a2[i]];
            f[i] = k;
        }
    }
    printf("%d", len);
    return 0;
}