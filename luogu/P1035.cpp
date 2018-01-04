#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, n = 0;
    cin >> k;
    for (double Sn = 0; Sn <= k; ++n, Sn += 1.0 / n)
        ;
    cout << n;
    return 0;
}