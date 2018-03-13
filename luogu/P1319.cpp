#include <iostream>
using namespace std;
int tot, n;
inline void PRINT(int x, int b)
{
    for (int i = 0; i < x; i++)
    {
        if (++tot > n)
        {
            cout << endl;
            tot = 1;
        }
        cout << b;
    }
}
int main()
{
    cin >> n;
    int x;
    bool zero = 0;
    while (cin >> x)
    {
        PRINT(x, zero);
        zero = !zero;
    }
    return 0;
}