#define LOCAL // For Windows
#define TEST
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
char mp[] = {
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M'};
inline void translate(int n, int m)
{
    if (n == 0)
        return;
    else
    {
        if (n > 0 || n % m == 0)
        {
            translate(n / m, m);
            cout << mp[n % m];
            return;
        }
        else
        {
            translate(n / m + 1, m);
            cout << mp[-m + n % m];
            return;
        }
    }
}
int main()
{
    INIT_CIN; // std::cin的优化
    int n, r;
    cin >> n >> r;
    cout << n << "=";
    translate(n, r);
    cout << "(base" << r << ")";
#ifdef TEST
#endif
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}

// typedef double db;
// typedef pair<ll, ll> pii;
// const int maxn = 1000 + 5;
// const int INF = 0x7f7f7f7f;
// const int SUP = -0x7f7f7f7f;