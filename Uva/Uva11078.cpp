#include <cstdio>
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int read()
{
    int x = 0, f = 1;
    char ch;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}
void put(int x)
{
    int num = 0;
    char c[15];
    while (x)
        c[++num] = (x % 10) + 48, x /= 10;
    while (num)
        putchar(c[num--]);
}
int x, ans = 0, maxa = 0, maxsofar = 0, n, t;
int main()
{
    t = read();
    while (t--)
    {
        n = read();
        maxa = read();
        maxsofar = read();
        ans = maxa - maxsofar;
        for (register int i = 2; i < n; i++)
        {
            x = read();
            ans = max(ans, maxa - x);
            maxa = max(maxa, x);
        }
        put(ans);
    }
    return 0;
}