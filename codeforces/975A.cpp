#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int n;
bool s[1005][26];
char str[1005];
string ans[1005];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        int len = strlen(str);
        for (int j = 0; j < len; j++)
        {
            char ch = str[j];
            s[i][ch - 'a'] = true;
        }
        for (int d = 'a'; d <= 'z'; d++)
        {
            if (s[i][d - 'a'])
                ans[i] += d;
        }
    }
    int as = 1;
    sort(ans + 1, ans + 1 + n);
    for (int i = 2; i <= n; i++)
    {
        if (ans[i] != ans[i - 1])
            as++;
    }
    printf("%d", as);
    return 0;
}