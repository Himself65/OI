#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 500 + 5;
string a1, b1;
int a[maxn], b[maxn], c[maxn];
int a1_len, b1_len, lenc, i, x;
int main()
{
    cin >> a1;
    cin >> b1;
    a1_len = a1.length();
    b1_len = b1.length();
    for (i = 0; i <= a1_len - 1; i++)
    {
        a[a1_len - i] = a1[i] - '0';
    }
    for (i = 0; i <= b1_len - 1; i++)
    {
        b[b1_len - i] = b1[i] - '0';
    }
    lenc = 1;
    x = 0;
    while (lenc <= a1_len || lenc <= b1_len)
    {
        c[lenc] = a[lenc] + b[lenc] + x;
        x = c[lenc] / 10;
        c[lenc] = c[lenc] % 10;
        lenc++;
    }
    c[lenc] = x;
    if (c[lenc] == 0)
    {
        lenc--;
    }
    for (i = lenc; i >= 1; i--)
    {
        cout << c[i];
    }
    cout << endl;
    return 0;
}