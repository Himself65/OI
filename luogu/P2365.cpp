#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5000 + 5;
int n, s, t[maxn], m[maxn], f[maxn];
inline int min(int a, int b) { return a < b ? a : b; }
int main()
{
    scanf("%d%d", &n, &s);
    memset(f + 1, 0x3f3f3f3f, sizeof(f) - sizeof(int));
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &t[i], &m[i]), t[i] += t[i - 1], m[i] += m[i - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i] = min(f[i], f[j - 1] + s * (m[n] - m[j - 1]) + t[i] * (m[i] - m[j - 1]));
    // 前一个任务 + 剩余任务长度 + 花费
    cout << f[n];
    return 0;
}