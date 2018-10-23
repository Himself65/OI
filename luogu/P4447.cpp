#define LOCAL // For Windows
#define TEST
// #define DATA
#define HAND
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
int n, tot, ans;
int a[maxn];
map<int, priority_queue<int, vector<int>, greater<int> > > mp;
inline void solve()
{
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    for (register int i = 1; i <= n; i++)
    {
        if (mp.count(a[i] - 1) && mp[a[i] - 1].size())
        {
            int t = mp[a[i] - 1].top() + 1;
            mp[a[i]].push(t);
            mp[a[i] - 1].pop();
        }
        else
            mp[a[i]].push(1);
    }
    ans = 3e8;
    for (auto it : mp)
        if (it.second.size())
            ans = min(ans, it.second.top());
    printf("%d\n", ans);
}
} // namespace BREAD
int main()
{
#ifdef LOCAL
#ifdef DATA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#endif
    BREAD::solve();
#ifdef TEST
#endif
#ifdef LOCAL
#ifdef HAND
    system("pause");
#endif
#endif
    return 0;
}
