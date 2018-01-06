#include <iostream>
#include <cstdio>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    INIT_CIN;   // std::cin的优化
    ll a, b;
    cin >> a >> b;
    b = (a * 10 + b) / 19;
    cout << b;
    return 0;
}