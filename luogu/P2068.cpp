#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int n, w;
int a[maxn];
inline int lb(int x) { return x & (-x); }
inline void add(int x, int v)
{
    while (x <= n)
    {
        a[x] += v;
        x += lb(x);
    }
}
inline int ask(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += a[x];
        x -= lb(x);
    }
    return ans;
}
int main()
{
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= w; i++)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        // cout << op << " " << a << " " << b << endl;
        if (op == 'x')
            add(a, b);
        else
            printf("%d\n", ask(b) - ask(a - 1));
    }
    return 0;
}