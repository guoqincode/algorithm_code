//给定一个 n(n≤3e5)个点，m(m≤1e6)条边的有向图
//每个节点有一个数，现在要求找到一条路径，路径节点中的最大值减去最小值的差最大
//即路径上节点值的极差最大，输出最大的差。

#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
const int maxm=1e6+10;
int n,m;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int from,to,next;
}edge[maxm];

int tot=0,head[maxn];

inline void addedge(int from,int to){
    tot++;
    edge[tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

struct Node{
    int id,val;
}node[maxn];
int a[maxn];

bool cmp(Node a,Node b){
    return a.val<b.val;
}

int ans;
int vis[maxn];
int MiN,MaX;
inline void dfs(int u){
    if(vis[u]) return;
    vis[u]=1;
    MaX = max(MaX,a[u]);
    //起点就是最小值
    ans = max(ans,MaX-MiN);

    for(int i=head[u]; i; i=edge[i].next){
        int v=edge[i].to;
        dfs(v);
    }
    
}

int main(){
    n=read(); m=read();
    
    for(int i=1;i<=n;i++){
        node[i].id=i;
        node[i].val=read();
        a[i]=node[i].val;
    }
    
    for(int i=1;i<=m;i++){
        int u,v;
        u=read(); v=read();
        addedge(u,v);
    }
    sort(node+1,node+n+1,cmp);

    for(int i=1;i<=n;i++){
        MiN=MaX=node[i].val;
        dfs(node[i].id);
    }

    cout<<ans;
    return 0;
}


