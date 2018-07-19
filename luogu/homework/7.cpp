#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
long long maxt = -0x3f3f3f3f;
int main()
{
    cin >> n;
    while (n--)
    {
        long long t;
        cin >> t;
        if (t > maxt)
            ans++;
        maxt = max(maxt, t);
    }
    cout << ans;
    return 0;
}