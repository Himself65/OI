#include<iostream>
using namespace std;
float a;
float s,x;
int main()
{
    ios::sync_with_stdio(false);
    cin >> s>>x;
    bool can = true;
    float v = 7.0f;
    int len = 0;
    while(true)
    {
        if (len >= s - x)
            if (len + v <= s + x)
            {
                can = false;
                break;
            }
        if ( len > s)
            break;
        len+=v;
        v*= 0.98f;
    }
    if(can)
        cout <<"n";
    else
        cout <<"y";
    cin >> s;
    return 0;
}