#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int maxn = -100000;
int minn = 100000;
int uper[26];
int lower[26];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline int min(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    return a < b ? a : b;
}
inline bool isprime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i < sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    INIT_CIN; // std::cin的优化
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            lower[str[i] - 'a'] += 1;
        }
        else
        {
            uper[str[i] - 'A'] += 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        maxn = max(uper[i], maxn);
        minn = min(uper[i], minn);
    }
    for (int i = 0; i < 26; i++)
    {
        maxn = max(lower[i], maxn);
        minn = min(lower[i], minn);
    }
    if (maxn - minn == 0)
        cout << "No Answer" << endl
             << "0";
    else if (isprime(maxn - minn))
        cout << "Lucky Word" << endl
             << maxn - minn;
    else
        cout << "No Answer" << endl
             << "0";
    return 0;
}