#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
int main()
{
    int n;
    cin >> n;
    while (true)
    {
        if (n == 1)
            break;
        else if (n % 2)
        {
            cout << n << "*3+1=";
            n = n * 3 + 1;
            cout << n << endl;
        }
        else if ((n + 1) % 2)
        {
            cout << n << "/2=";
            n = n / 2;
            cout << n << endl;
        }
    }
    cout << "End";
    return 0;
}