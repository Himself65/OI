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
typedef double db;
ll x1, x2, wa = 0, wb = 0;

inline void init()
{
    ll i = x1;
    while (i)
    {
        i /= 10;
        wa++;
    }
    i = x2;
    while (i)
    {
        i /= 10;
        wb++;
    }
}
bool isPrime(int b)
{
    for (int k = 2; k <= sqrt(b); ++k)
        if (b % k == 0)
            return false;
    return true;
}
inline void solve()
{
    if (wa <= 1 && wb >= 1)
    {
        if ((x1 <= 5) && (x2 >= 5))
            cout << 5 << endl;
        if ((x1 <= 7) && (x2 >= 7))
            cout << 7 << endl;
    }
    if ((wa <= 2) && (wb >= 2))
    {
        if ((x1 <= 11) && (x2 >= 11))
            cout << 11 << endl;
    }
    if ((wa <= 3) && (wb >= 3))
    {
        for (int a = 1; a <= 9; a += 2)
            for (int b = 0; b <= 9; ++b)
            {
                int f = a * 100 + b * 10 + a;
                if (f < x1)
                    continue;
                if (f > x2)
                    return;
                if (isPrime(f))
                    cout << f << endl;
            }
    }
    if ((wa <= 5) && (wb >= 5))
    {
        for (int a = 1; a <= 9; a += 2)
            for (int b = 0; b <= 9; ++b)
                for (int c = 0; c <= 9; ++c)
                {
                    int f = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
                    if (f < x1)
                        continue;
                    if (f > x2)
                        return;
                    if (isPrime(f))
                        cout << f << endl;
                }
    }
    if ((wa <= 7) && (wb >= 7))
    {
        for (int a = 1; a <= 9; a += 2)
            for (int b = 0; b <= 9; ++b)
                for (int c = 0; c <= 9; ++c)
                    for (int d = 0; d <= 9; ++d)
                    {
                        int f = a * 1000000 + b * 100000 + c * 10000 + d * 1000 + c * 100 + b * 10 + a;
                        if (f < x1)
                            continue;
                        if (f > x2)
                            return;
                        if (isPrime(f))
                            cout << f << endl;
                    }
    }
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> x1 >> x2;
    init();
    solve();
    return 0;
}