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
    return 0;
}