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
const int maxn = 3e6 + 5;
int n, p;
int inv[maxn];
int main()
{
    scanf("%d%d", &n, &p);
    inv[1] = 1;
    putchar('1');
    putchar('\n');
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;  // 逆元线性筛
        printf("%d\n", inv[i]);
    }
#ifdef TEST
#endif
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;