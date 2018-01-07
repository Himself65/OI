#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 15;
char c[maxn];
char temp[maxn];
int main()
{
    INIT_CIN;   // std::cin的优化
    
    for (int i = 0; i <= 12; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i <= 12; i++)
    {
        temp[i] = c[i];
        c[i] = c[i] - '0';
    }
    ll ans = c[0] * 1 + c[2] * 2 + c[3] * 3 + c[4] * 4 + c[6] * 5 + c[7] * 6 + c[8] * 7 + c[9] * 8 + c[10] * 9;
    ans = ans % 11;
    ll cp = temp[12] - '0';
    if (temp[12] == 'X')
        cp = 10;
    if (ans == cp)
        cout << "Right";
    else
    {
        if (ans != 10)
            temp[12] = ans + '0';
        else
            temp[12] = 'X';
        for (int i = 0; i <= 12; i++)
        {
            cout << temp[i];
        }
    }
    return 0;
}