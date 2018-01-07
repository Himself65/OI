#include<iostream>
#include<cmath>
using namespace std;
int x[22], n, k;
bool isprime(int n)
{
    int s = sqrt(double(n));
    for (int i = 2; i <= s; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int dfs(int choose_left_num, int already_sum, int start, int end)
{
    if (choose_left_num == 0)
        return isprime(already_sum);
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += dfs(choose_left_num - 1, already_sum + x[i], i + 1, end);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << dfs(k, 0, 0, n - 1);
}