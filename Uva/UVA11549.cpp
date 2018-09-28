#define LOCAL
#define TEST
#include <cmath>
#include <iostream>
using namespace std;
int T, n, k;
inline int max(int a, int b) { return a > b ? a : b; }
typedef long long ll;
int buf[105];
inline int next(int n, int k)
{
    if (!k)
        return 0;
    ll k2 = (ll)k * k; // next k;
    int l = 0;
    while (k2 > 0) // load to buf
    {
        buf[l++] = k2 % 10;
        k2 /= 10;
    }
    if (n > l)
        n = l;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = ans * 10 + buf[--l];
    return ans;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int ans = k, k1 = k, k2 = k;
        do
        {
            k1 = next(n, k1);
            k2 = next(n, k2);
            ans = max(ans, k2);
            k2 = next(n, k2);
            ans = max(ans, k2);
        } while (k1 != k2);
        cout << ans << endl;
    }
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}