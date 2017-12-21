#include<iostream>
#include<stack>
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
// 尝试新的方法写
using namespace std;
const int maxn = 1005;
int main()
{_
    int t;
    cin >> t;
    while(t--)
    {
        int num;
        int train[maxn];
        cin >> num;
        for (int i = 1; i <= num; i++)
        {
            cin >> train[i];
        }
        stack<int> s;
        int a = 1, b = 1;
        bool ok = true;
        while (b <= num)
        {
            if (a == train[b]) 
            {
                a++;
                b++;
            }
            else if (!s.empty() && s.top() == train[b])
            {
                s.pop();
                b++;
            }
            else if (a <= num)
            {
                s.push(a++);
            }
            else 
            {
                ok = false;
                break;
            }
        }
        cout << (ok == 1 ? "Possible" : "Impossible") << endl;
    }
    return 0;
}