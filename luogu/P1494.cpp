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
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 5e+5 + 5;
struct node
{
    int l, r, id;
    ll a, b;
} q[maxn];
#define Square(x) (x) * (x)
ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    else
        return gcd(b, a % b);
}
int n, m, col[maxn], unit, block[maxn], l = 1, r = 0;
ll sum[maxn], ans;
inline bool cmp(const node &a, const node &b) { return block[a.l] == block[b.l] ? a.r < b.r : a.l < b.l; }
inline bool cmp2(const node &a, const node &b) { return a.id < b.id; }
void revise(int x, int add) { ans -= Square(sum[col[x]]), sum[col[x]] += add, ans += Square(sum[col[x]]); }
int main()
{
    scanf("%d%d", &n, &m);
    unit = sqrt(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &col[i]), block[i] = i / unit + 1;
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        while (l < q[i].l)
            revise(l, -1), l++;
        while (l > q[i].l)
            revise(l - 1, 1), l--;
        while (r < q[i].r)
            revise(r + 1, 1), r++;
        while (r > q[i].r)
            revise(r, -1), r--;

        if (q[i].l == q[i].r)
            q[i].a = 0, q[i].b = 1;
        else
        {
            q[i].a = ans - (q[i].r - q[i].l + 1), q[i].b = 1LL * (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
            ll g = gcd(q[i].a, q[i].b);
            q[i].a /= g, q[i].b /= g;
        }
    }
    sort(q + 1, q + m + 1, cmp2);
    for (int i = 1; i <= m; i++)
        printf("%lld/%lld\n", q[i].a, q[i].b);
    return 0;
}