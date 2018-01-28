#include <iostream>
using namespace std;
typedef long long ll;
ll a[100];
int n;
void solve()
{
    for (int i = 4; i <= 60; i++)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
}

int main()
{
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    solve();
    while (cin >> n)
    {
        cout << a[n] << endl;
    }
    return 0;
}