#define LOCAL // For Windows
#define TEST
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
const int maxn = 1e5 + 5;
int n, l, a;
int b[maxn];
int ans;
int main()
{
    scanf("%d%d%d", &n, &l, &a);
    int s = 0, t = 0, s2 = 0, t2 = 0;
    if (n != 0)
    {
        scanf("%d%d", &s, &t);
        ans = (s - 0) / a;
        for (int i = 2; i <= n; i++)
        {

            scanf("%d%d", &s2, &t2);
            ans += (s2 - (s + t)) / a;
            s = s2, t = t2;
        }
    }
    ans += (l - (s + t)) / a;
    cout << ans;
#ifdef TEST
#endif
#ifdef LOCAL
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;