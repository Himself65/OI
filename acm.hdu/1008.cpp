#include<iostream>
using namespace std;

int n;
int temp;
int t = 0;
int f = 0;

inline void solve() {
    int h = temp - f;
    if (h > 0)
        t += 6 * h;
    else if (h < 0)
        t += 4 * (-h);
    t += 5;
    f = temp;

}

int main(){
    while (true)
    {
        t = 0;
        f = 0;
        cin >> n;
        if (n == 0)
            break;
        while(n--)
        {
            cin >> temp;
            solve();
        }
        cout << t << endl;
    }
    return 0;
}