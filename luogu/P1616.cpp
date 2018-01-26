#include <iostream>
using namespace std;
int t, m;
const int maxn = 1000000 + 5;
typedef long long ll;

ll f[maxn];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> m;
    int w, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> w;
        cin >> c;
        for (int j = w; j <= t; j++)
            f[j] = max(f[j], f[j - w] + c);
    }
    cout << f[t];
    return 0;
}