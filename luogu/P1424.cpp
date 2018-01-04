#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    ll sum = 0;
    int now = x;
    while (n--)
    {
        if (now == 6)
        {
            now++;
            continue;
        }
        if (now == 7)
        {
            now = 1;
            continue;
        }
        sum += 250;
        now++;
    }
    cout << sum;
    return 0;
}