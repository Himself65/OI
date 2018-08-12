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
const int maxn = 1e+5 + 5;
int n, w, m, ans;
int a[maxn], f[maxn];
int main()
{
    // INIT_CIN; // std::cin的优化
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++)
    {
        int p, v;
        scanf("%d%d", &p, &v);
        m = max(m, p);
        a[p] += v;
    }

    for (int i = 1; i <= m; i++)
        f[i] = a[i] + f[i - 1];
    for (int i = 1; i <= m - w + 1; i++)
        ans = max(ans, f[i + w - 1] - f[i - 1]);
    printf("%d", ans);
    // system("pause");
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;