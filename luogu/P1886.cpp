#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
const int maxn = 1e6 + 5;
int q1[maxn], q2[maxn], a[maxn];
inline void min_deque()
{
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h <= t && q1[h] + m <= i)
            h++;
        while (h <= t && a[i] < a[q1[t]])
            t--;
        q1[++t] = i;
        if (i >= m)
            printf("%d ", a[q1[h]]);
    }
    printf("\n");
}
inline void max_deque()
{
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h <= t && q2[h] + m <= i)
            h++;
        while (h <= t && a[i] > a[q2[t]])
            t--;
        q2[++t] = i;
        if (i >= m) // 到达所需宽度
            printf("%d ", a[q2[h]]);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    min_deque();
    max_deque();
    return 0;
}