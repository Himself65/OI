#include <cstring>
#include <iostream>
using namespace std;
#define LOW_BIT(x) ((x) & (-x))
const int maxn = 500000 + 5;
int tree[maxn * 2 + 1];
int n, m;

inline void set(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += LOW_BIT(x);
    }
}

inline void set(int l, int r, int k)
{
    set(l, k);
    set(r + 1, -k);
}

inline int find(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= LOW_BIT(x);
    }
    return sum;
}

inline void init()
{
    int last = 0, now;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        set(i, now - last);
        last = now;
    }
}

inline void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            set(l, r, k);
        }
        else
        {
            int x;
            cin >> x;
            cout << find(x) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    solve();
    return 0;
}