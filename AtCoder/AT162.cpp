#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'A')
            ans += 4;
        else if (ch == 'B')
            ans += 3;
        else if (ch == 'C')
            ans += 2;
        else if (ch == 'D')
            ans += 1;
    }
    if (ans == 0)
        printf("0\n");
    else
        printf("%.12lf", (double)ans / n);
    return 0;
}