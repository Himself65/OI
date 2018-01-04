#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    float x;
    cin >> x;
    float sum = 0.0f;
    int c = 0;
    float s = 2.0f;
    while (sum < x)
    {
        sum += s;
        s *= 0.98f;
        c++;
    }
    cout << c;
    return 0;
}