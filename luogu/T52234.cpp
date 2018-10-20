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
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int SUP = -0x3f3f3f3f;
namespace BREAD
{
int n, m, k;
int a[maxn];
int b[maxn];
} // namespace BREAD
using namespace BREAD;
int main()
{
    // INIT_CIN;
    scanf("%d%d%d", &k, &n, &m);
    for (register int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (register int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        b[x]++;
    }
    int ans = 0;
    for (register int i = 1; i <= k; i++)
    {
        ans = ans + max(0, (a[i] - b[i]));
    }
    printf("%d", ans);
    return 0;
}
