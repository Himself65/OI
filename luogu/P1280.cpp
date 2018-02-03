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
const int maxn = 10000 + 5;
const int INF = 0x7f7f7f7f;
int n, k;
struct Node
{
    int p, t;
} task[maxn];
int dp[maxn], sum[maxn];
inline bool compare(Node &a, Node &b)
{
    if (a.p == b.p)
        return a.t < b.t;
    return a.p > b.p;
}

inline int min(int a, int b)
{
    return a < b ? a : b;
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline void solve()
{
    dp[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        if (sum[i] == 0)    // 这个时刻无任务可做
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            for (int j = 1; j <= k; j++)
            {
                if (task[j].p == i)
                    dp[i] = max(dp[i + task[j].t], dp[i]);
            }
        }
    }
    cout << dp[1];
}

int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> task[i].p >> task[i].t;
        sum[task[i].p]++;
    }
    sort(task + 1, task + k + 1, compare);
    solve();
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int SUP = -0x7f7f7f7f;