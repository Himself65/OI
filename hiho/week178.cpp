/*
最近小嗨加入了算法学习小组。
该组由一个算法主和N个成员组成。
成员编号从1到N.每个成员都有一个或多个其他成员作为他的导师。
有些成员的导师是他自己的主人。
每个成员每个星期都会向他的导师发送自己的学习进度报告和从学生那里收集的报告（如果有的话）。
这个团队设计得非常好，报告链上没有任何循环，所以没有人收到他自己的报告。
最后主人得到每一个人的报告（也许不止一次）。
小嗨注意到，对于一些成员来说，他们向主人报告的路线很容易被一个成员（除了主人和他自己）以外的报告职责中断。
他们被称为不稳定的成员，而其他的则是稳定的成员。
鉴于该组织的报告网络，你能找出有多少成员是稳定的？
假设组中有4名成员。
成员1和2都有主人作为唯一的导师。
会员3有2个导师：会员1和会员2，会员4有1个导师：会员3，则会员4是团队中唯一不稳定的会员，因为如果会员3不在场，他的学习报告将无法发送给主人

输入
第一行包含一个整数N，即成员的数量。
以下N行的第i行描述了第i个成员的导师。
第一个整数是Ki，第i个成员的导师的数量。然后按照Ki的整数A1 ... AN，这是他的导师的号码。数字0表示主人是他的导师之一。
对于40％的数据，1≤N≤1000。
对于100％的数据，1≤N≤100000。
对于100％的数据，1≤Ki≤10，Ki <N，0≤Ai≤N。
输出
输出稳定成员的数量。
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10e+4;
int n;

inline int read(){
	int x=0;char ch=' ';int f=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}

struct student {
    vector<student *> master;
    bool isMaster;
};
student stu[maxn];

inline bool isStable(student *s) {
    if(s->isMaster)
        return true;
    for (int i = 0; i < s->master.size(); i++) {
        if(stu[i].master[0]->isMaster)
            return true;
    }
    return false;
}
set<int> c;
inline void solve() {
    int number = n;
    for (int i = 0; i < n; i++)
    {
        if (!isStable(stu + i))
             
    }
    cout << number;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++)
    {
        int temp = read();
        for (int i = 0; i < temp; i++)
        {
            int t = read();
            for (int j = 0; j < t; j++) {
                if (j == i)
                    stu[i].isMaster = true;
                stu[i].master.push_back(stu + j);
            }
        }
    }
    solve();
    // system("pause");
    return 0;
}