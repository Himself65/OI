#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 1000000 + 5;
ll heap[maxn + 1];
ll sz = 0;

inline void push(ll x)
{
    ll i = sz++;
    while (i > 0)
    {
        ll father = (i - 1) / 2;
        if (heap[father] <= x)
            break;
        heap[i] = heap[father];
        i = father;
    }
    heap[i] = x;
}

inline long long pop()
{
    ll ret = heap[0];
    ll x = heap[--sz];
    ll i = 0;
    while (i * 2 + 1 < sz)
    {
        ll a = i * 2 + 1;
        ll b = i * 2 + 2;
        if (b < sz && heap[b] < heap[a])
            a = b;
        if (heap[a] >= x)
            break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

inline ll top()
{
    return heap[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x;
            cin >> x;
            push(x);
        }
        else if (op == 2)
            cout << top() << endl;
        else
            pop();
    }
    return 0;
}