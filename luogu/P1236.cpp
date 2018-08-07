#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int a[10];
string str = "+-*/";
inline int cal(int a, int b, int type)
{
    // + - * /
    switch (type)
    {
    case 1:
        return a + b;
    case 2:
        return a - b > 0 ? a - b : b - a;
    case 3:
        return a * b;
    case 4:
        return !(b && a) ? -1 : max(a, b) % min(a, b);
    default:
        return 0x3f3f3f3f;
    }
}

inline char getCal(int type)
{
    switch (type)
    {
        case 1:
        return 
            break;
    
        default:
            break;
    }
}

inline int solve(int i, int type)
{
}
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        cin >> a[i];
    }
    solve(1, 1);
    return 0;
}