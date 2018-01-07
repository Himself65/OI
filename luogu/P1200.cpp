#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    INIT_CIN;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); ++i)
    {
        a[i] = tolower(a[i]);
    }
    for (int i = 0; i < b.length(); ++i)
    {
        b[i] = tolower(b[i]);
    }
    a = " " + a + " ";
    b = " " + b + " ";
    if (b.find(a) == string::npos)
        cout << -1;
    else
    {
        size_t al = b.find(a);
        size_t bt = b.find(a), s = 0;
        while (bt != string::npos)
        {
            ++s;
            bt = b.find(a, bt + 1);
        }
        cout << s << " " << al;
    }
    return 0;
}