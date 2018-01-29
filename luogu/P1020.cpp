#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int f[maxn];
int main()
{
    int n = 0;
    int l, r, mid;
    while (scanf("%d", &a[++n]) != EOF)
        continue;
    n--;
    f[0] = 0x7f7f7f7f;
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[ans1] >= a[i])
            f[++ans1] = a[i];
        else
        {
            l = 0;
            r = ans1;
            while (l < r)
            {
                mid = (l + r) / 2;
                if (f[mid] >= a[i])
                    l = mid + 1;
                else
                {
                    r = mid;
                }
            }
            if (l != 0)
                f[l] = a[i];
        }
    }
    cout << ans1 << endl;
    memset(f, -1, sizeof(f));
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[ans2] < a[i])
            f[++ans2] = a[i];
        else
        {
            l = 0;
            r = ans2;
            while (l < r)
            {
                mid = (l + r) / 2;
                if (f[mid] >= a[i])
                    r = mid;
                else
                {
                    l = mid + 1;
                }
            }
            f[l] = a[i];
        }
    }
    cout << ans2 << endl;
}