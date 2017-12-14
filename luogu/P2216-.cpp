#include<cstring>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
const int maxn = 1001;

inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Node {
    int x, y, v;

    inline bool operator>(const Node &b) const {
        return v > b.v;
    }

    inline bool operator<(const Node &b) const {
        return v < b.v;
    }

    inline bool operator==(const Node &b) const {
        return ((x == b.x) && (y == b.y));
    }

    inline Node &operator=(const Node &b) {
        x = b.x;
        y = b.y;
        v = b.v;
        return *this;
    }

    inline bool operator!=(const Node &b) const {
        return ((x != b.x) && (y != b.y));
    }

    inline int operator-(const Node &b) const {
        return v - b.v;
    }
};
struct Maxqueue {
    deque<Node> q, m;
    inline void push(const Node &x) {
        q.push_back(x);
        while (!m.empty() && m.back() < x) m.pop_back();
        m.push_back(x);
    }

    inline void pop() {
        if (q.empty())
            return;
        Node& x = q.front();
        q.pop_front();
        if (x == m.front())
            m.pop_front();
    }

    inline int size(){
        return q.size();
    }

    inline Node& top() {
        return m.front();
    }

    inline bool empty()
    {
        return size() < 1;
    }
    inline void clear()
    {
        q.clear();
        m.clear();
    }
};

struct Minqueue {
    deque<Node> q, m;
    inline void push(const Node &x) {
        q.push_back(x);
        while (!m.empty() && m.back() > x) m.pop_back();
        m.push_back(x);
    }

    inline void pop() {
        if (q.empty())
            return;
        Node& x = q.front();
        q.pop_front();
        if (x == m.front())
            m.pop_front();
    }

    inline int size(){
        return q.size();
    }

    inline Node& top() {
        return m.front();
    }

    inline bool empty()
    {
        return size() < 1;
    }

    inline void clear()
    {
        q.clear();
        m.clear();
    }
};
Node node[maxn][maxn];
Maxqueue qmax;
Minqueue qmin;
Node fmax[maxn][maxn];
Node fmin[maxn][maxn];
Node smax[maxn][maxn];
Node smin[maxn][maxn];
int ans = 0x7f7f7f7f;
int a, b, n;
int main() {
    a = read();
    b = read();
    n = read();
    for (int i = 1; i <= a; i++) 
    {
        for (int j = 1; j <= b; j++)
        {
            //数据输入
            node[i][j].x = i;
            node[i][j].y = j;
            node[i][j].v = read();
        }
    }
    for (int i = 1; i <= a; i++)  
    {  
        for (int j = 1; j < n; j++)
        {
            qmax.push(node[i][j]);
            qmin.push(node[i][j]);
        }
        for (int j = 1; j <= b - n + 1; j++)
        {
            qmin.push(node[i][j + n - 1]);
            qmax.push(node[i][j + n - 1]);
            while (qmin.top().y < j)
                qmin.pop();
            while (qmax.top().y < j)
                qmax.pop();
            fmin[i][j] = qmin.top();
            fmax[i][j] = qmax.top();
        }
        qmax.clear();
        qmin.clear();
    }

    for (int j = 1; j <= b; j++)
    {
        for (int i = 1; i < n; i++)
        {
            qmax.push(fmax[i][j]);
            qmin.push(fmin[i][j]);
        }
        for (int i = 1; i <= a - n + 1; i++)
        {
            qmin.push(fmin[i + n - 1][j]);
            qmax.push(fmax[i + n - 1][j]);
            while (qmin.top().x < i && !qmin.empty())
                qmin.pop();
            while (qmax.top().x < i && !qmax.empty())
                qmax.pop();
            smin[i][j] = qmin.top();
            smax[i][j] = qmax.top();
        }
        qmax.clear();
        qmin.clear();
    }

    for (int i = 1; i + n - 1 <= a; i++)  
    {  
        for (int j = 1; j + n - 1 <= b; j++)
        {
            ans = min(ans, smax[i][j] - smin[i][j]);
        }  
    }
    printf("%d", ans);
    return 0;
}