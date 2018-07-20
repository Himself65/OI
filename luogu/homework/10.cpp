#include <iostream>
using namespace std;
long long  n, k, t, x, flag, buy = 0;
int main()
{
    cin >> n >> k >> t;
    t %= k;
    for (long long i = 0; i < n; i++)
    {
        cin >> flag >> x;
        if (flag == 1)
        {
            t = (t + x)%k;
        }
        else
        {
            buy++;
            if (t < x)
            {
                cout << "qwq"
                     << " " << buy << endl;
            }
            else
            {
                t = t - x;
            }
        }
    }
    cout << t;
    return 0;
}