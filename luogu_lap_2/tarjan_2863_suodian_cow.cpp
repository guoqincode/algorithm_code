//p2863 缩点模板题目  求出具有1个点数以上的强连通分量的个数
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10,maxm=5e4+10;
int n,m,tot=0,head[maxn];
int cut[maxn],ans=0;
int low[maxn],dfn[maxn],stac[maxn],vis[maxn],top=0,tim=0;
struct Edge{
    int from;
    int to;
    int next;
}edge[maxm];

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void addedge(int from,int to){
    edge[++tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

inline void tarjan(int x){
    low[x]=dfn[x]=++tim;
    stac[++top]=x; vis[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(vis[v]){
            low[x]=min(low[x],low[v]);
        }
    }
    if(dfn[x]==low[x]){
        int y;
        while(y=stac[top--]){
            // sd[y]=x;
            cut[x]++;
            vis[y]=0;
            if(x==y) break;
        }
    }
}


int main(){
    n=read(); m=read();
    memset(cut,0,sizeof(cut));
    for(int i=1;i<=m;i++){
        int x,y;
        x=read(); y=read();
        addedge(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(cut[i]>1) ans++;
    }
    printf("%d",ans);
    return 0;
}