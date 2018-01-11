#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool a[1010];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(a, false, sizeof(a));
    while(n--)
    {
        int t;
        cin >> t;
        a[t] = true;
    }
    long ans = 0;
    queue<int> q;
    for (int i = 1; i <= 1000; i++)
        if(a[i])
        {
            ans++;
            q.push(i);
        }
    cout << ans << endl;
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}