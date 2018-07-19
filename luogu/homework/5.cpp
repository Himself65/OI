#include <algorithm>
#include <iostream>
using namespace std;
int ten = 0;
int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
            {
                if (i < j && j < k)
                    cout << i * 100 + j * 10 + k << " ", ten++;
                if (ten == 10)
                    cout << endl, ten = 0;
            }
    return 0;
}