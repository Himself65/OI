#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll in[13];
ll money = 0;
ll ans = 0;
ll save = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 12; i++)
    {
        cin >> in[i];
        money += 300;
        money -= in[i];
        if (money >= 0)
        {
            if (money >= 100)
            {
                save += money / 100;
                money -= money / 100 * 100;
            }
        }
        else
        {
            cout << -i;
            return 0;
        }
    }
    cout << save * 120 + money;
    return 0;
}