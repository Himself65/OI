#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
std::map<int, int> mp;
int w, cnt = 0, L, R, Q;
inline void init()
{
    mp[1] = 31;
    mp[2] = 28;
    mp[3] = 31;
    mp[4] = 30;
    mp[5] = 31;
    mp[6] = 30;
    mp[7] = 31;
    mp[8] = 31;
    mp[9] = 30;
    mp[10] = 31;
    mp[11] = 30;
    mp[12] = 31;
}
int main()
{
    init();
    cin >> L >> R >> Q;
    bool flag = true;
    if (L <= Q && Q <= R)
    {
        cout << "Yes"
             << " ";
        while (L < R && flag)
        {
            if (L == Q)
                flag = false;
            int tmp = L % 10000 / 100;
            int year = (int)L / 10000;
            if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && tmp == 2)
                w = 29;
            else
                w = mp[tmp];
            int day = L % 100;
            if (day == w)
            {
                L = L - w + 101;
                int month = L % 10000 / 100;
                if (month == 13)
                    L = L - 1301 + 10101;
            }
            else
                L++;
            if (flag)
                cnt++;
        }
        cout << cnt << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}