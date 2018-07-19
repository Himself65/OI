#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        int t;
        cin >> t;
        if (30 + n >= t)
            ans++;
    }
    cout << ans;
    return 0;
}