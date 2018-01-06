#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll m;
    double ans = 0.0f;
    scanf("%lld", &m);
    if (m > 400)
        ans = 0.5663 * (m - 400) + 0.4663 * 250 + 0.4463 * 150;
    else if (m > 150)
        ans = 0.4663 * (m - 150) + 0.4463 * 150;
    else
        ans = 0.4463 * m;
    printf("%.1f", ans);
    return 0;
}