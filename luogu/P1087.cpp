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
typedef long long ll;
typedef unsigned long long ull;
int n;
char s[8848];
inline void mk(int from, int to)
{
    int mid = (from + to) >> 1, a = 0, b = 0;
    if (from != to)
        mk(from, mid), mk(mid + 1, to);
    for (int i = from; i <= to; i++)
        if (s[i] == '0')
            a++;
        else
            b++;
    if (a && b)
        std::cout << "F";
    else if (a)
        std::cout << "B";
    else
        std::cout << "I";
}
int main()
{
    std::cin >> n >> (s + 1);
    mk(1, (1 << n));
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;