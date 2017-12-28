#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000 + 5;
int n;
int first;
int ans;
struct Node
{
    int v;
    vector<int> child;
    Node() : v(0) { child.clear(); }
};
Node node[maxn];
queue<int> q;
bool vis[maxn];
inline void solve()
{
    ans = 0;
    q.push(first);
    node[first].v = 1;
    queue<int> ansqueue;
    while (!q.empty())
    {
        Node &temp = node[q.front()];
        q.pop();
        while (!temp.child.empty())
        {
            int s = temp.child.back();
            temp.child.pop_back();
            Node &t = node[s];
            t.v += temp.v;
            if (t.child.empty() && vis[s] == false)
            {
                ansqueue.push(s);
                vis[s] = true;
            }
            else
                q.push(s);
        }
    }

    while(!ansqueue.empty())
    {
        ans += node[ansqueue.front()].v;
        ansqueue.pop();
    }
    cout << endl
         << ans << endl;
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            int t;
            cin >> t;
            node[i].child.push_back(t);
        }
    }
    cin >> first;
    solve();
    return 0;
}