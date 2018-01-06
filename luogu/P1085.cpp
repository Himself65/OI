#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll s[8];
int main()
{
    for (int i = 1; i <= 7; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a + b > 8)
            s[i] = 100;
    }
    for (int i = 1; i <= 7; i++)
    {
        if (s[i] > 1)
        {
            cout << i;
            break;
        }
    }
    return 0;
}