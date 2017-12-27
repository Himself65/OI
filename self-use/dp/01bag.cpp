#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <unistd.h>
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

inline void solve()
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[1][W];
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
    solve();
    cout << endl
         << clock() - before << "ms" << endl;
    // display();
    return 0;
}