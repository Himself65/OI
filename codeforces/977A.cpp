#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, k;
    cin >> a >> k;
    while (k--)
    {
        if (a % 10 == 0)
        {
            a = a / 10;
        }
        else
        {
            a--;
        }
    }
    cout << a;
    return 0;
}