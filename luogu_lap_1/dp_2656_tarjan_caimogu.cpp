//dp p2656 采蘑菇 tarjan缩点后重新建图 + spfa + dp
#include<bits/stdc++.h>
using namespace std;
int n,m,st; //点数 边数 起点
const int maxn=8e4+10, maxm=2e5+10;
int w[maxn];    //每一个强连通分量的走完的总距离
const int inf=0x3f3f3f3f;

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
    double f;
}edge[maxm],edge2[maxm];
int tot=0,head[maxn];
inline void addedge(int from,int to,int dis,double f){
    tot++;
    edge[tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    
    edge[tot].dis=dis;
    edge[tot].f=f;
    head[from]=tot;
}
int tot2=0,head2[maxn];
inline void addedge2(int from,int to,int dis){
    tot2++;
    edge2[tot2].from=from;
    edge2[tot2].to=to;
    edge2[tot2].next=head2[from];
    edge2[tot2].dis=dis;
    head2[from]=tot2;
}

int sd[maxn],dfn[maxn],low[maxn],stac[maxn],vis[maxn],tim=0,top=0,col=0;
inline void tarjan(int x){
    low[x] = dfn[x] = ++tim;
    stac[++top]=x;
    vis[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(vis[v]){
            low[x]=min(low[x],low[v]);
        }
    }
    if(dfn[x] == low[x]){
        col++;
        int y;
        while(y=stac[top--]){
            sd[y]=col;
            vis[y]=0;
            if(x==y) break;
        }
    }
}

int d[maxn],isinq[maxn];
queue<int>q;
inline void spfa(){
    fill(d,d+maxn,-1);  //inf ->-1 30'->100'   这里求得是最大值 所以一开始要初始化为最小值
    q.push(st);
    isinq[st]=1;
    d[st]=w[st];
    while(!q.empty()){
        int u=q.front();
        q.pop();
        isinq[u]=0;
        for(int i=head2[u];i;i=edge2[i].next){
            int v=edge2[i].to;
            int dis=edge2[i].dis;
            if(d[v]<d[u]+dis+w[v]){
                d[v]=d[u]+dis+w[v];
                if(!isinq[v]){
                    q.push(v);
                    isinq[v]=1;
                }
            }
        }
    }
}

int main(){
    // scanf("%d %d",&n,&m);
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int from,to,dis; double f;
        from=read(); to=read(); dis=read();
        scanf("%lf",&f);
        addedge(from,to,dis,f);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }

    //tarjan 完成之后 按照各个强连通分量来建立新图
    for(int i=1;i<=m;i++){
        int x=sd[edge[i].from],y=sd[edge[i].to];
        if(x==y){
            //如果在相同的连通分量里边
            int t=edge[i].dis;
            while(t){
                w[x]+=t;
                t=(int)t*edge[i].f;
            }
        }else{
            //如果在不同的强连通分量里面 就给新的强连通分量建图
            addedge2(x,y,edge[i].dis);
        }
    }
    
    scanf("%d",&st);
    st=sd[st];  //把st换成他所在的强连通分量

    spfa();

    int ans=0;
    for(int i=1;i<=col;i++) ans=max(ans,d[i]);
    
    cout<<ans;
    return 0;
}