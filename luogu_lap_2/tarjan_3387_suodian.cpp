//tarjan 缩点模板  Tarjan缩点＋DAGdp
//未成功 50'
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

const int maxn=1e4+15;
int n,m,p[maxn];
int head[maxn],tot=0;
int tim=0,top,s,h[maxn],in[maxn],dist[maxn];
int dfn[maxn],low[maxn],stac[maxn],vis[maxn],sd[maxn];
//dfn(u)为节点u被搜索到时候的次序编号，low(u)为u或u的子树能追溯到的最早的栈中的节点中的次序号
//栈只是为了表示此时是否有父子关系


struct Edge{
    int from;
    int to;
    int next;
}edge[maxn*10],edge2[maxn*10];  //edge2[]为把每个强连通分量合并后的图

inline void addedge(int from,int to){
    tot++;
    edge[tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}


inline void tarjan(int x){
    tim++;
    low[x]=dfn[x]=tim;
    stac[++top]=x;vis[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(vis[v]){
            low[x]=min(low[x],low[v]);
        }
        if(dfn[x]==low[x]){
            //此时，x一定是环上一点，且环上的其他点就是x的子树
            int y;
            while(y=stac[top--]){
                sd[y]=x;    //y属于x
                vis[y]=0;
                if(x==y) break;
                p[x]+=p[y];
            }
        }
    }
}
int ans=0;
inline void topo(){
    queue<int>q;
    int toto=0;
    for(int i=1;i<=n;i++){
        if(sd[i]==i&&!in[i]){
            q.push(i);
            dist[i]=p[i];
        }
    }
    while(!q.empty()){
        int k=q.front();q.pop();
        for(int i=h[k];i;i=edge2[i].next){
            int v=edge2[i].to;
            dist[v]=max(dist[v],dist[k]+p[v]);  //动态规划
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    // int ans=0;
    for(int i=1;i<=n;i++) printf("topo:%d  : %d      \n",i,dist[i]);
    for(int i=1;i<=n;i++) ans=max(ans,dist[i]);
    // return ans;
}

int main(){
    // n=read(); m=read();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=m;i++){
        int u,v;
        // u=read(); v=read();
        scanf("%d%d",&u,&v);
        addedge(u,v);        
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=m;i++){
        int x=sd[edge[i].from],y=sd[edge[i].to];
        if(x!=y){
            //两个点属于两个不同的连通分量
            edge2[++s].next=h[x];
            edge2[s].to=y;
            edge2[s].from=x;
            h[x]=s;
            in[y]++;
        }
    }
    for(int i=1;i<=n;i++) printf("p%d  :  %d\n",i,p[i]);
    // printf("%d",topo());
    topo();
    printf("%d\n",ans);
    return 0;
}