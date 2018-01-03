#include <iostream>
using namespace std;
typedef long long ll;

template <typename type>
type gcd(type a, type b)
{
    if (b == 0) // 
        return a;
    return gcd(b, a % b);
}

int main()
{
    ll a, b;
    a = 252;
    b = 105;
    cout << gcd(a, b);
}