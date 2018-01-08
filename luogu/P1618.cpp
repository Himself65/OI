#include <algorithm>
#include <cmath>
#include <cstdio>
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
int x[10];

void solve(int a, int b, int c)
{
    bool noans = true;
    for (int i = 1; i <= 9; i++)
    {
        x[i] = i;
    }
    do
    {
        int x1 = x[1] * 100 + x[2] * 10 + x[3];
        int x2 = x[4] * 100 + x[5] * 10 + x[6];
        int x3 = x[7] * 100 + x[8] * 10 + x[9];
        if (double(x1) / x2 == double(a) / b && double(x2) / x3 == double(b) / c)
        {
            printf("%d %d %d\n", x1, x2, x3);
            noans = false;
        }
    } while (next_permutation(x + 1, x + 10));
    if (noans)
        cout << "No!!!";
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
    return 0;
}