#include <algorithm>
#include <iostream>
using namespace std;
int n;
int maxt = -1;
int mint = 10000;
int main()
{
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        maxt = max(maxt, t);
        mint = min(mint, t);
    }
    cout << maxt - mint;
    return 0;
}