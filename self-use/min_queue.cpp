#include <cstdio>
#include <iostream>
#include <queue>
const int maxn = 2000000 + 5;
int n, m;
int hp[maxn];
int sz = 0;
#define lc(x) ((x << 1) + 1)
#define rc(x) ((x << 1) + 2)
#define fa(x) ((x - 1) >> 1)
inline void push(int x)
{
    int i = sz++;
    while (i > 0)
    {
        int p = fa(i);
        if (hp[p] <= x)
            break;
        hp[i] = hp[p];
        i = p;
    }
    hp[i] = x;
}
inline int top() { return hp[0]; }
inline void pop()
{
    int x = hp[--sz];
    int i = 0;
    while (lc(i) < sz)
    {
        int a = lc(i), b = rc(i);
        if (b < sz && hp[b] < hp[a])
            a = b; // 如果 `b` 小
        if (hp[a] >= x)
            break;
        hp[i] = hp[a], i = a;
    }
    hp[i] = x;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", top());
        push(t);
        if (sz > m)
            pop();
    }
    system("pause");
    return 0;
}