// 例题一

/**
 * 反着搜索，比正搜快
 * 反搜的状态减少
 */
#include <iostream>

void dfs(int depth, int left)
{
    if (depth == 0)
        output();
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && left % a[i] == 0)
            {
                vis[i] = 1;
                dfs(depth - 1, left - a[i]);
                vis[i] = 0;
            }
        }
    }
}