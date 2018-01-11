#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
stack<char> s;
char re[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main()
{
    INIT_CIN; // std::cin的优化
    string str;
    cin >> str;
    int i = 0;
    bool f = false;
    if (str[0] == '-')
    {
        f = true;
        i = 1;
    }
    for (; i < str.length(); i++)
    {
        char a = re[str[i] - '0'];
        s.push(a);
    }
    if (f)
        cout << "-";
    while (!s.empty() && s.top() == '0')
        s.pop();
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}