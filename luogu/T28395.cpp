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
int n;
double a[maxn];   // needed
double b[maxn];   // have
double c[maxn];   // output
double qzh[maxn]; // exist power
double ct[maxn];
double ans = 0;
int main()
{
    scanf("%d%lf", &n, &b[0]);
    c[0] = b[0];
    qzh[0] = c[0];
    ans += b[0];
    for (int i = 1; i <= n; i++)
    {
        long long rg = 0;
        scanf("%lf %lld", &a[i], &rg);
        double needed = a[i] * 5; //需要吃多少
        ct[i] += needed;
        if (qzh[rg] - needed < 0)
        {
            printf("-1");
            return 0;
        }
        c[i] = needed * 0.2;
        qzh[i] = qzh[i - 1] - ct[i] + c[i];
    }
    printf("%lf", qzh[n] * 0.2);
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;