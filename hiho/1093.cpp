#include<cstring>  
#define maxn 0x7f7f7f7f  
#include<queue>  
#include<cstdio>
#include<functional>
using namespace std;  
int n,m,f,h[1000005]; 
long long sumq = 0; 
int dist[100005],vis[100005],head[100005];  
struct node  
{  
    int  e,w,next;  
}edge[1000005];  
void add(int s,int e,int w)  
{  
        edge[f].e=e;  
        edge[f].w=w;  
        edge[f].next=head[s];//同一起点的下一条边存储在edge数组中的位置  
        head[s]=f++;  
}  
void spfa(int s)  
{
    int cur, k, i;
    queue<int> q;
    q.push(s);  
    dist[s]=0;  
    vis[s]=1;  
    h[s]=1;
    sumq = dist[s];
    while(!q.empty())  
    {  
       cur=q.front();  
       q.pop();  
       while (dist[cur] > (sumq / (q.size() + 1))) {
            q.push(cur);
            cur = q.front();
            q.pop();
        }
        sumq -= dist[cur];
       vis[cur]=0;  
       for(i=head[cur];i!=-1;i=edge[i].next)  
       {  
         k=edge[i].e;  
         if(dist[k]>dist[cur]+edge[i].w)  
         {  
             dist[k]=dist[cur]+edge[i].w;  
             if(!vis[k])  
             {
                 sumq += dist[k];
                 vis[k] = 1;
                 q.push(k);  
             }  
         }  
       }  
    }  
}  
int main()  
{
    int s, t, i, a, b, w;
    scanf("%d %d %d %d",&n,&m,&s,&t);  
    memset(vis,0,sizeof(vis));  
    for(i=0;i<100005;i++)
        dist[i]=maxn,head[i]=-1;  
        f=0;  
    for(i=0;i<m;i++)  
    {  
        scanf("%d %d %d",&a,&b,&w);  
        add(a,b,w);  
        add(b,a,w);  
    }  
    spfa(s);  
    printf("%d\n",dist[t]);

    return 0;  
}  