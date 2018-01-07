#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
stack<char> leftstack;
stack<char> rightstack;
int main()
{
    INIT_CIN;
    string a;
    cin >> a;
    bool toshort = true;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '0')
        {
            toshort = false;
            break;
        }
    }
    if(toshort)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < a.size(); i++)
    {
        char c = a[i];
        if (c >= '0' && c <= '9')
        {
            if (!leftstack.empty() || c != '0')
                leftstack.push(c);
        }
        else
        {
            if (c == '.')
            {
                while (++i < a.length())
                {
                    if (a[i] == '0')
                        continue;
                    else
                        rightstack.push(a[i]);
                }
                if (rightstack.empty())
                    rightstack.push('0');
                rightstack.push('.');
                break;
            }
            else if (c == '/')
            {
                while (++i < a.length())
                {
                    rightstack.push(a[i]);
                }
                while (!rightstack.empty() && rightstack.top() == '0')
                    rightstack.pop();
                if (rightstack.empty())
                    rightstack.push('0');
                rightstack.push('/');
                break;
            }
            else
            {
                rightstack.push('%');
                break;
            }
        }
    }
    while (!leftstack.empty() && leftstack.top() == '0') //保证顶部没有0
        leftstack.pop();
    if(leftstack.empty())
    {
        cout << "0";
    }
    else while (!leftstack.empty())
            {
                cout << leftstack.top();
                leftstack.pop();
            }
    while (!rightstack.empty())
    {
        cout << rightstack.top();
        rightstack.pop();
    }
    return 0;
}
//01247
//74210