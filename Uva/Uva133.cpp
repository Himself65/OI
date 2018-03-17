#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define clr(x) clear(x, v)
inline void clear(int x, vector<int> &v)
{
    vector<int>::iterator ite = v.begin();
    for (int i = 0; i < v.size(); i++, ite++)
        if (v[i] == x)
            v.erase(ite);
}
int main()
{
    while (true)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0)
            break;
        vector<int> v;
        v.clear();
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        int posk = 0;
        int posm = 0;
        while (true)
        {
            if (v.size() == 0)
                break;
            int len = v.size();
            posk = (posk + k) % (len);
            if (posm - m < 0)
                m -= posm, posm = len - 1 - m;
            else
                posm = (posm - m) % (len);
            int dm = v[posk];
            int dk = v[posm];
            if (dm == dk)
            {
                printf("%d ", dm);
                clr(dm);
            }
            else
            {
                printf("%d %d ", dm, dk);
                clr(dm);
                clr(dk);
            }
        }
    }
    return 0;
}