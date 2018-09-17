#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 2e5 + 5;
priority_queue<int> q1, q2;
int n, R, L, ans;
int a[maxn], f[maxn];
int main()
{
    scanf("%d %d %d", &n, &L, &R);
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < L; i++)
        q2.push(a[i]);
    for (int i = L; i <= n; i++)
    {
        q1.push(f[i - L]);
        if (i - R - 1 >= L)
            q2.push(f[i - R - 1]);
        while (!q2.empty() && q1.top() == q2.top())
        {
            q1.pop();
            q2.pop();
        }
        f[i] = q1.top() + a[i];
    }
    for (int i = n - R + 1; i <= n; i++)
        ans = max(ans, f[i]);
    printf("%d\n", ans);
}