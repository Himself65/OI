// 例题二

/**
 * T = len^2T/c
 * 卡出一个下届
 * source: https://www.lydsy.com/JudgeOnline/problem.php?id=5439
 */
#include <string>
using namespace std;

int n;
char s[100010];

long long check(const string &p)
{
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == p[cur])
        {
            cur++;
            if (cur == p.size())
            {
                cur = 0;
                cnt++;
            }
        }
    }
    return 1ll * p.size() * cnt * cnt;
}

string curs;
long long ans = 0;
void dfs(int i)
{
    if (i > 6)
        return;
    if (i)
        ans = max(ans, check(curs));
    for (int j = 0; j < 3; j++)
    {
        curs.push_back('a' + j);
        dfs(i + 1);
        curs = curs.substr(0, curs.size() - 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (scanf("%d", &n) != -1)
    {
        ans = 0;
        curs = "";
        scanf("%s", s);
        dfs(0);
        printf("%lld\n", ans);
    }
}