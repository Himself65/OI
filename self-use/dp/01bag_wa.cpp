//此代码只适用于n~10的情况，否则会超时
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>
using namespace std; 
const int maxn = 105;
const int maxw = 10005;
int dp[maxn + 1][maxw + 1];
int w[maxn], v[maxn];
int n, W;
clock_t before;

inline int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

inline int solve(int i, int j)
{
    int res;
    if (i == n)
        return 0;
    else if (j < w[i])
        res = solve(i + 1, j);
    else
        res = max(solve(i + 1, j), solve(i + 1, j - w[i]) + v[i]);
    return res;
}

inline void display()
{
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "------" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << " " << v[i] << endl;
    }
    cout << endl;
}

int main()
{
    before = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << solve(1, W) << endl;
    cout << endl
         << clock() - before << "ms" << endl;
    // display();
    return 0;
}