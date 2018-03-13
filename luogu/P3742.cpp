#include <cstdio>
int main()
{
    int n, i;
    char x[101], z[101], y[101];
    scanf("%d%s%s", &n, x, z);
    for (i = 0; i < n; i++)
    {
        if (x[i] >= z[i])
            y[i] = z[i];
        else
        {
            printf("%d", -1);
            return 0;
        }
    }
    for (i = 0; i < n; i++)
        printf("%c", y[i]);
    return 0;
}