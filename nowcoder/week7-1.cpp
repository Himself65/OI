#include <iostream>
using namespace std;

inline int read(){
	int x=0;char ch=' ';int f=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}

int main()
{
    int T, i, j, cn1, cn2;
    int a[6], b[6];
    T = read();
    while (T--)
    {
        cn1 = 0;
        cn2 = 0;
        for (i = 0; i < 6; i++)
            a[i] = read();
        for (i = 0; i < 6; i++)
            b[i] = read();
        for (i = 0; i < 6; i++)
            for (j = 0; j < 6; j++)
            {
                if (a[i] > b[j])
                    cn1++;
                if (a[i] < b[j])
                    cn2++;
            }
        if (cn1 == cn2)
            printf("Tie\n");
        if (cn1 > cn2)
            printf("Alice\n");
        if (cn1 < cn2)
            printf("Bob\n");
    }
    return 0;
}