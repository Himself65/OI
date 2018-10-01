typedef long long ll;
int n;
void dfs(int last, ll mul)
{
    if (mul == n)
    {
        update();
    }
    else
        for (int i = last;; i++)
        {
            // i == (n / mul)
            if (mul * i <= n /* && n % (mul * i) == 0 */)
                dfs(i, mul * i);
            else
                break;
        }
}