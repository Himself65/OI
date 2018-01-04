#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, i, x, b, c, t = 0;
    cin >> n >> x;
    for (i = 1; i <= n; i++)
    {
        b = i;
        while (b != 0)
        {
            c = b % 10;
            b = b / 10;
            if (c == x)
                t++;
        }
    }
    cout << t << endl;
    return 0;
}