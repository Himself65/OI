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
const int INF = 0x3f3f3f3f;
struct Node
{
    int width, height;
} a[110];
int n, k, ans = INF, f[110][110];
inline int abs(int a) { return a > 0 ? a : -a; }
inline bool cmp(const Node &a, const Node &b) { return a.height < b.height; }
inline int min(int a, int b) { return a < b ? a : b; }
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].height >> a[i].width;
    sort(a + 1, a + 1 + n, cmp);
    memset(f, INF, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[1][i] = 0;
    int remain = n - k;
    for (int i = 2; i <= remain; i++)
        for (int j = i; j <= n; j++)
            for (int m = 1; m <= j - 1; m++)
                f[i][j] = min(f[i][j], f[i - 1][m] + abs(a[m].width - a[j].width));
    for (int i = 1; i <= n; i++)
        ans = min(ans, f[remain][i]);
    cout << ans;
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;