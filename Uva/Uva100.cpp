#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
namespace BREAD
{
    int f(int n)
    {
        int count = 1;
        while (n != 1)
        {
            count++;
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
        }
        return count;
    }
    inline void solve()
    {
        using namespace std;
        int i, j;
        while (scanf("%d", &i) != EOF)
        {
            scanf("%d", &j);
            printf("%d %d ", i, j);
            if (i > j)
                swap(i, j);
            int res = 1;
            for (int pos = i; pos <= j; pos++)
                res = max(res, f(pos));
            printf("%d\n", res);
        }
    }
} // namespace BREAD
int main()
{
    BREAD::solve();
    return 0;
}
