#include <iostream>
using namespace std;
int d[11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 10; i++)
    {
        cin >> d[i];
    }
    int n;
    cin >> n;
    n += 30;
    int ans = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (n >= d[i])
            ans++;
    }
    cout << ans;
    return 0;
}