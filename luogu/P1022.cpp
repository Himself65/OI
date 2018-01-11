#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define INIT_CIN                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
char x;
ll coe, value, opp = 1; //coe表示系数，value表示值，opp表示在等号左边还是右边
double ans;
int main()
{
    char c = getchar(); //为了节省空间当然要在线
    ll cur = 0, sign = 1;
    bool value_gotten = false; //cur为当前读入的数值，sign表示当前数值符号，value_gotten是一个标记变量，字面意思是是否读入过数值，用途下面说
    while (true)
    {
        if (c >= 'a' && c <= 'z')
        {
            x = c;
            if (cur == 0 && !value_gotten)
                coe += opp * sign, value_gotten = false; //这也是个坑点（虽然数据没有涉及），如果cur为0又读入了变量名称有两种情况：一时+0x或-0x，另一种是默认系数为1，value_gotten专门判断这两种情况
            else
                coe += opp * sign * cur, cur = 0, sign = 1, value_gotten = false;
        }
        else if (c == '-')
            value += -opp * sign * cur, cur = 0, sign = -1, value_gotten = false; //如果是减号把当前数值加入值（如果之前是变量则当前数值为0，加入也没有影响），并清空当前数值，设value_gotten为false，符号修改为负
        else if (c == '+')
            value += -opp * sign * cur, cur = 0, sign = 1, value_gotten = false; //加号和减号一样，只是把符号修改为正
        else if (c >= '0' && c <= '9')
            cur = cur * 10 + c - '0', value_gotten = true; //如果是数字，就对cur进行计算，并把value_gotten设为true
        else if (c == '=')
            value += -opp * sign * cur, cur = 0, sign = 1, opp = -opp, value_gotten = false; //等号和加减号差不多，只是要把opp设为负
        else
        {
            value += -opp * sign * cur;
            break;
        } //最后的值累加上去
        c = getchar();
    }
    ans = double(value) / coe;                        //计算ans
    printf("%c=%.3lf", x, ans == 0 ? abs(ans) : ans); //这涉及一个很坑的地方：C++里0除以一个负数值为-0，专门避免这种情况
    return 0;
}