#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,b,a) for(int i=b;i>=a;i--)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
char ch;
void read(int &n){n=0;int p=1;for(ch=getchar();ch<'0' || ch>'9';ch=getchar())if(ch=='-') p=-1;for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';n*=p;}
const int N=5e5+5;
int n,ans,m,c[N],fa[N],st[N],size[N];
ll a[N];
struct op
{
    int tp,x,y;
}b[N];
int getfa(int x){return fa[x]?getfa(fa[x]):x;}
void link(int x,int y,int z)
{
    ++m;
    st[m]=0,c[m]=c[m-1],a[m]=a[m-1];
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy) return;
    if(size[fx]>size[fy]) swap(fx,fy),swap(x,y);
    st[m]=fx,++c[m],a[m]+=z;
    fa[fx]=fy,size[fy]+=size[fx];
}
void del(int cnt)
{
    for(int x=st[m];cnt--;x=st[--m])
    {
        for(int y=fa[x];y;y=fa[y]) size[y]-=size[x];
        fa[x]=0;
    }
}
void output(int x)
{
    if(c[x]==n-1) printf("%lld\n",a[x]);
    else puts("0");
}
int main()
{
    freopen("uoj#14.in","r",stdin);
    freopen("uoj#14.out","w",stdout);
    int T;
    read(n),read(T);
    fo(i,1,T)
    {
        for(ch=getchar();!('A'<=ch && ch<='Z');ch=getchar());
        if(ch=='A') read(b[i].x),read(b[i].y),b[i].tp=1;
        else
        if(ch=='D') read(b[i].x),b[i].tp=2;
        else b[i].tp=3;
    }
    fo(i,1,n) size[i]=1;
    fo(i,1,T)
    {
        int x=b[i].x,y=b[i].y;
        if(b[i].tp==1)
        {
            link(x,y,i);
            output(m);
            if(b[i+1].tp==3) del(1);
        }else
        if(b[i].tp==2)
        {
            output(m-x);
            if(b[i+1].tp!=3) del(x);
        }
        else output(m);
    }
    return 0;
}