#include <algorithm>
#include <iostream>
using namespace std;
int n;
long long ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}