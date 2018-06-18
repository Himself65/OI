#include <iostream>
#include <string>
inline int abs(int a) { return a > 0 ? a : -a; }
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, number;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        cin >> number;
        if (number)
        {
            if (i != n && number > 0)
                cout << "+";
            if (abs(number) > 1 || i == 0)
                cout << number;
            if (number == -1 && i)
                cout << "-";
            if (i > 1)
                cout << "x^" << i;
            if (i == 1)
                cout << "x";
        }
    }
    return 0;
}