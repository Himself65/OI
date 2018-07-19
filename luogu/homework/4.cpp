#include <algorithm>
#include <iostream>
using namespace std;
int n, x;
int main()
{
    cin >> x;
    for (int i = 2; i <= x; i++)
    {
        int n = i * i;
        if ((n % 1000 == i) || (n % 100 == i) || (n % 10 == i))
        {
            if (i != x)
                cout << i << " ";
            else
                cout << i;
        }
    }
    return 0;
}