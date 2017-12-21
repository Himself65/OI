#include<iostream>
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;
int cnt1(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        if (x % 2)
            cnt++;
        x = x / 2;
        cout << cnt << endl;
    }
    return cnt;
}
int main() {
    int x;
    int a[60];
    scanf("%d", &x);
    for (int i = 0; i < 60; i++)
        a[i] = cnt1(i);
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (a[i] + a[j] == x)
                printf("%02d:%02d\n", i, j);
        }
    }
    return 0;
}