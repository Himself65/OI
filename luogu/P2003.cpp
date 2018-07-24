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
const int maxn = 100 + 5;
int n, lcost, rcost, ans;
struct node
{
    int x1, x2, y, width;
    node() {}
    node(int _x1, int _x2, int _y, int _width) : x1(_x1), x2(_x2), y(_y), width(_width) {}
} b[maxn];
inline bool cmp(const node &a, const node &b) { return a.y < b.y; } // 越高越靠前
inline bool checkr(int l, int r, int x)
{
    if (l < x && x < r)
        return true;
    if (l < x && x == r)
        return true;
    return false;
}
inline bool checkl(int l, int r, int x)
{
    if (l < x && x < r)
        return true;
    if (l == x && x < r)
        return true;
    return false;
}
inline void init()
{
    b[0].x1 = -1;
    b[0].x2 = 0x3f3f3f3f;
    b[0].width = 0x3f3f3f3f + 1;
}
int main()
{
    INIT_CIN; // std::cin的优化
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        int width = abs(x2 - x1);
        b[i] = node(x1, x2, y, width);
    }

    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        lcost = -1, rcost = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (lcost != -1 && rcost != -1)
                break; // have ans
            if (b[j].y < b[i].y)
            {
                // 计算花费
                if (lcost == -1 && checkl(b[j].x1, b[j].x2, b[i].x1))
                    lcost = b[i].y - b[j].y;
                if (rcost == -1 && checkr(b[j].x1, b[j].x2, b[i].x2))
                    rcost = b[i].y - b[j].y;
            }
        }
        ans += lcost + rcost;
    }
    cout << ans;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;