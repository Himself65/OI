#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const char yes[30][50] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
int num[27] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};
int i, j, number[50], top, first;
char s[10086];
int main()
{
    while (cin >> s)
        if (s[0] == '.')
            break;
        else
            for (j = 1; j <= 27; j++)
                if (!strcmp(s, yes[j]))
                {
                    number[++top] = num[j];
                    break;
                }
    sort(number + 1, number + 1 + top);
    for (i = 1; i <= top; i++)
        if (first)
            printf("%.2d", number[i]);
        else if (number[i])
            printf("%d", number[i]), first = true;
    if (!first)
        cout << 0;
    return 0;
}