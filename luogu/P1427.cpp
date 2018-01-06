#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    INIT_CIN;   // std::cin的优化
    stack<ll> s;
    while (true)
    {
        ll num;
        cin >> num;
        if (num == 0)
            break;
        s.push(num);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}