#include <cmath>
#include <iostream>
using namespace std;
int n, ans;
double h, s1, v, l, k;
int main()
{
    cin >> h >> s1 >> v >> l >> k >> n;
    for (int i = 0; i < n; i++)
        if (i < 0.0001 + (s1 - sqrt((h - k) / 5) * v) + l && i > (s1 - sqrt(h / 5) * v) - 0.0001)
            ans++;
    cout << ans;
    return 0;
}