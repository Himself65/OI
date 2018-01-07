#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const ll maxn = 300005,maxm = 500005;
ll f[maxn],r[maxn]; // father, rank

ll find(ll x) {
    return f[x]==x?x:find(f[x]);
}

void merge(ll x,ll y) {
    if(r[x]>r[y])swap(x,y);
    f[x] = y;
    r[y] += r[x];
    int t = f[y];
    while(f[t]!=t)r[t]+=r[x],t = f[t];
}

void del(ll x,ll y) {
    if(f[y]==x)swap(x,y);
    f[x] = x;
    r[y]-=r[x];
    int t = f[y];
    while(f[t]!=t)r[t]-=r[x],t = f[t];
}
struct comment {
    ll op,a,b;
} c[maxm];

struct edge {
    ll a,b,w;
    bool exist;
};

vector<edge> s;

inline ll init(){   // int输入优化
    ll x = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c))x = x*10+c-'0',c = getchar();
    return x;
}

void out(ll x){ //输出优化
    if(x>9)out(x/10);
    putchar('0'+x%10);
}

void scan(char op[]){   // 输入数据
    int head = 0;
    char c = getchar();
    while(c==' '||c=='\n')c = getchar();
    while(c!=' '&&c!='\n')op[head++] = c,c = getchar();
}

int main() {
    ll n = init(),m = init();
    for(ll i = 1; i<=n; ++i)f[i] = i,r[i] = 1;
    char op[10];
    for(ll i = 1; i<=m; ++i) {
        scan(op);
        if(op[0]=='A') {
            c[i].op = 1;
            c[i].a = init(),c[i].b = init();
        } else if(op[0]=='D') {
            c[i].op = 2;
            c[i].a = init();
        } else c[i].op = 0;
    }
    ll ans = 0,cnt = 0;
    for(ll i = 1; i<=m; ++i) {
        if(!c[i].op) {
            edge e = s.back();
            s.pop_back();
            if(e.exist)del(e.a,e.b),ans -= e.w,cnt--;
            out(cnt==n-1?ans:0);
            putchar('\n');
        } else if(c[i].op==1) {
            ll a = find(c[i].a),b = find(c[i].b);
            if(a==b)s.push_back((edge) {a,b,i,0});
            else s.push_back((edge) {a,b,i,1}),merge(a,b),ans+=i,cnt++;
            out(cnt==n-1?ans:0);
            putchar('\n');
        } else if(c[i].op==2) {
            if(i+1<=m&&!c[i+1].op) {
                ll old = ans,k = c[i].a;
                for(int j = s.size()-1,end = j-k;i>=end;j--){
                    edge e = s[j];
                    if(e.exist){
                        ans = 0;
                        break;
                    }
                    k--;
                }
                out(ans);putchar('\n');out(cnt==n-1?old:0);putchar('\n');
                ans = old;
                i++;
            } else {
                ll k = c[i].a;
                while(k) {
                    edge e = s.back();
                    s.pop_back();
                    if(e.exist)del(e.a,e.b),ans -= e.w,cnt--;
                    k--;
                }
                out(cnt==n-1?ans:0);
                putchar('\n');
            }
        }
    }
}