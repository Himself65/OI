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
ll f[1000][1000];
int n, m, a, x;
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> a >> n >> m >> x;
    f[1][0] = a;
    f[1][1] = 0;
    f[1][2] = a;
    for (int i = 0; i <= 20; i++)
    {
        f[2][0] = i;
        f[2][1] = i;
        f[2][2] = a;
        for (int j = 3; j < n; j++)
        {
            f[j][0] = f[j - 1][0] + f[j - 2][0];
            f[j][1] = f[j - 1][0];
            f[j][2] = f[j - 1][2] + f[j][0] - f[j][1];
        }
        if (f[n - 1][2] == m)
        {
            printf("%lld\n", f[x][2]);
            return 0;
        }
    }
    return 0;
}