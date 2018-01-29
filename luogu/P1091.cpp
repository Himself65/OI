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
int n, ans;
int a[105];
int f[2][105];
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                f[0][i] = max(f[0][i], f[0][j] + 1);
    }
    a[n + 1] = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = n + 1; j > i; j--)
            if (a[i] > a[j])
                f[1][i] = max(f[1][i], f[1][j] + 1);
    }
    for (int i = 1; i <= n; i++)
        ans = max(f[0][i] + f[1][i] - 1, ans);
    cout << n - ans;
    return 0;
}
