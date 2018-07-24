#include <iostream>
using namespace std;
int n, row, column, ans, tot;
int a[45][45];
inline void solve()
{
    row = 1;
    column = n / 2 + 1;
    ans = n * n;
    a[row][column] = ++tot;
    while (true)
    {
        if (ans == 0)
            break;
        else
            ans--;
        if (row == 1 && column != n)
        {
            a[row = n][column = column + 1] = ++tot;
        }
        else if (row != 1 && column == n)
        {
            a[row = row - 1][column = 1] = ++tot;
        }
        else if (row == 1 && column == n)
        {
            a[row = row + 1][column] = ++tot;
        }
        else if (row != 1 && column != n)
        {
            if (!a[row - 1][column + 1])
            {
                // k - 1 右上方未被填满
                a[row = row - 1][column = column + 1] = ++tot;
            }
            else
            {
                // k - 1 正下方
                a[row = row + 1][column] = ++tot;
            }
        }
    } // end for
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    cin >> n;
    solve();
    return 0;
}