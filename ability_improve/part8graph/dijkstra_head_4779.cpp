//带堆优化的dijkstra算法 速度快于普通dijkstra 快于sfpa
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxm=2e5+10;
const int inf=0x3f3f3f3f;
int n,m,st;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int from;
    int to;
    int next;
    int dis;
}edge[maxm];
int tot=0,head[maxn];
inline void addedge(int from,int to,int dis){
    tot++;
    edge[tot].from=from;
    edge[tot].to=to;
    edge[tot].dis=dis;
    edge[tot].next=head[from];
    head[from]=tot;
}

struct eedge{
    //利用小顶堆来记录最小的边
    int u,d;
    bool operator < (const eedge& x) const{
        return x.d<d;   //优先队列第一个是最小的那个
    }
};

priority_queue<eedge>q;

int dis[maxn],vis[maxn];
inline void dijkstra(int st){
    fill(dis,dis+maxn,inf);
    dis[st]=0;
    q.push(eedge{st,0});
    while(q.size()){
        auto temp=q.top();
        q.pop();
        if(vis[temp.u]) continue;
        vis[temp.u]=1;
        int x=temp.u;
        for(int i=head[x];i;i=edge[i].next){
            int y=edge[i].to;
            if(dis[y]>dis[x]+edge[i].dis){
                dis[y]=dis[x]+edge[i].dis;
                if(!vis[y]) q.push(eedge{y,dis[y]});
            }
        }
    }
}


int main(){
    n=read(); m=read(); st=read();
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read(); v=read(); w=read();
        addedge(u,v,w);
    }
    dijkstra(st);
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    return 0;
}