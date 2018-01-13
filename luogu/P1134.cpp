#include <iostream>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll n, ans = 1;
int main()
{
    INIT_CIN;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i;
        while (ans % 10 == 0)
            ans /= 10;
        ans = ans % 100000000;
    }
    cout << ans % 10;
    return 0;
}