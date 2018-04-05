#include <iostream>
using namespace std;
inline void solve(int mod)
{
    bool ans = true;
    for (int a = 1; a <= 3; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                for (int d = 0; d <= 9; d++)
                {
                    for (int e = 0; e <= 9; e++)
                    {
                        int sum = a * 10000 + b * 1000 + c * 100 + d * 10 + e;
                        if (sum > 30000)
                            break;
                        int i = a * 100 + b * 10 + c;
                        int j = b * 100 + c * 10 + d;
                        int k = c * 100 + d * 10 + e;
                        if (i % mod == 0 && j % mod == 0 && k % mod == 0)
                        {
                            cout << sum << endl;
                            ans = false;
                        }
                    }
                }
            }
        }
    }
    if (ans)
        cout << "No";
}
int main()
{
    int k;
    cin >> k;
    solve(k);
    return 0;
}