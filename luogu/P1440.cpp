#include <deque>
#include <iostream>
using namespace std;

struct MinQueue
{
    deque<int> q, m;
    void push(const int &x)
    {
        q.push_back(x);
        while (!m.empty() && m.back() > x)
            m.pop_back();
        m.push_back(x);
    }

    void pop()
    {
        int x = q.front();
        q.pop_front();
        if (x == m.front())
            m.pop_front();
    }

    int size()
    {
        return q.size();
    }

    bool empty()
    {
        return q.empty();
    }

    int top()
    {
        return m.front();
    }
};
int main()
{
    MinQueue q;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        if (i > 1)
            printf("%d\n", q.top());
        else
            printf("0\n");
        q.push(t);
        if (q.size() > m)
            q.pop();
    }
    system("pause");
    return 0;
}