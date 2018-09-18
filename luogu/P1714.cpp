#define LOCAL
#include <cstdio>
#include <deque>
#include <iostream>
using namespace std;
const int maxn = 5e+5 + 5;
int s[maxn], q[maxn];
int n, m;
inline int max(int a, int b) { return a > b ? a : b; }
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        s[i] += s[i - 1] + k;
    }

    // `h`: head
    // `t`: end
    // `m`: width
    int ans = -0x3f3f3f3f;
    int h = 1, t = 0; // 队列为空
    for (int i = 1; i <= n; i++)
    {
        while (h <= t && s[q[t]] >= s[i]) // 队列尾部 `s[q[t]]` 大于目前 `s[i]`
            t--;
        q[++t] = i;
        if (q[h] < i - m) // q.size
            h++;
        ans = max(ans, s[i] - s[q[h]]);
    }

    printf("%d", ans);
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}
