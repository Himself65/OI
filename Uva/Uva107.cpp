#include <cmath>
#include <cstdio>
int i, m, n, sum1, sum2, num, tmp, x;
inline void init()
{
    num = 1;
    sum1 = sum2 = 0;
}
int main()
{
    while (scanf("%d%d", &m, &n) != -1 && m && n)
    {
        init();
        while (fabs(log(num) / log(num + 1) - log(n) / log(m)) > 1e-10)
            num++;
        x = (int)(log(m) / log(num + 1) + 0.5); // 上取整
        for (i = 0; i < x; i++)
        {
            tmp = (int)(pow(num, i));
            sum1 += tmp;
            sum2 += m * tmp;
            m /= (num + 1);
        }
        sum2 += (int)(pow(num, i));
        printf("%d %d\n", sum1, sum2);
    }
    return 0;
}