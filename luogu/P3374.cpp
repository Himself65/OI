#include <cstring>
#include <iostream>
using namespace std;
#define LOW_BIT(x) ((x) & (-x))
#define MAX_INT 0x7f7f7f7f
const int maxn = 500000 + 5;
int tree[maxn * 2 + 1];
int n, m; // n个元素 m次操作
inline void init()
{
    memset(tree, MAX_INT, sizeof(tree));
}

inline void add(int k, int x)
{
    while (x <= n)
    {
        tree[x] += k;
        x += LOW_BIT(x);
    }
}

inline int presum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= LOW_BIT(x);
    }
    return sum;
}

inline int sum(int i, int j)
{
    return presum(j) - presum(i - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        add(k, i);
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, k;
            cin >> x >> k;
            add(k, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << sum(l, r) << endl;
        }
    }
    return 0;
}