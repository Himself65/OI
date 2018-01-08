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

bool prime(unsigned E)
{
    unsigned e = 2;
    while (e <= sqrt(E))
        if (!(E % e++))
            return false;
    return true;
}

int main()
{
    INIT_CIN;
    int n;
    cin >> n;
    for (int x = 2;; ++x)
        for (int y = x; n - x - y >= y; ++y)
            if (prime(x) && prime(y) && prime(n - x - y))
                return !printf("%u %u %u\n", x, y, n - x - y);
    return 0;
}