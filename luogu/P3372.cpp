#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define Left_Child(x) (x << 1)
#define Right_Child(x) (x << 1 | 1)
#define Mid(l, r) ((l + r) / 2)
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7f7f7f7f;
const int maxn = 1e5 + 5;
const int maxq = 1e5 + 5;
int N, M;
int a[maxn];
char T[maxq];
int l[maxq], r[maxq], x[maxq];

ll bit0[maxn], bit1[maxn];

ll sum(ll *b, int i)
{
    ll s = 0;
    while (i > 0)
    {
        s += b[i];
        i -= i & -i;
    }
    return s;
}

void add(ll *b, int i, int v)
{
    while (i <= N)
    {
        b[i] += v;
        i += i & -i;
    }
}

inline void solve()
{
    for (int i = 1; i <= N; i++)
        add(bit0, i, a[i]);

    for (int i = 0; i < M; i++)
    {
        if (T[i] == '1')
        {
            add(bit0, x[i], -x[i] * (l[i] - 1));
            add(bit1, l[i], x[i]);
            add(bit0, r[i] + 1, x[i] * r[i]);
            add(bit1, r[i] + 1, -x[i]);
        }
        else
        {
            ll res = 0;
            res += sum(bit0, r[i]) + sum(bit1, r[i]) * r[i];
            res -= sum(bit0, l[i] - 1) + sum(bit1, l[i] - 1) * (l[i] - 1);
            cout << res << endl;
        }
    }
}

int main()
{
    INIT_CIN; // std::cin的优化
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
    {
    }
    return 0;
}