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
// #define LOCAl
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int n, m;
bool isPrime[10000005];
ll sums[10000005];

inline void solve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= m; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j <= m; j += i)
                isPrime[j] = false;
            sums[i]++;
        }
    }
    for (int i = 2; i <= m; i++)
        sums[i] += sums[i - 1];
    //
    cout << endl;
    for (int i = 2; i <= 7; i++)
    {
        cout << sums[i] << " ";
    }
    cout << endl;    
    for (int i = 2; i <= 7; i++)
    {
        cout << isPrime[i] << " ";
    }
    cout << endl;
    //
}
int main()
{
    INIT_CIN; // std::cin的优化
    cin >> n >> m;
    solve();
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        if (!(a < 1 || b > m))
            cout << sums[b] - sums[a - 1] << endl;
        else
            cout << "Crossing the line" << endl;
    }
    return 0;
}