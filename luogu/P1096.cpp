#include <iostream>
using namespace std;

int main()
{
    int n;
    long long ans = 2;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        ans *= 2;
    }
    cout << ans - 1;
}