#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        ll be = sqrt(l);
        ll c = 0;
        while (1)
        {
            if (be*be > r)
                break;
            if (be * be <= r && be * be >= l)
            {
                c++;
            }
            be++;
        }
        cout << c;
        cout << endl;
    }
    return 0;
}