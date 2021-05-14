//p2015 二叉苹果树  树形dp  树形背包问题
#include<bits/stdc++.h>
using namespace std;
const int maxn=100;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int w;
    int to;
    int next;
}edge[maxn<<1];
int tot=0,head[maxn];

inline void addedge(int from,int to,int w){
    edge[++tot].to=to;
    edge[tot].next=head[from];
    edge[tot].w=w;
    head[from]=tot;
}

int f[maxn][maxn];      //f[u][i]代表以u为根的子树保留i条边->ans=dp[1][q]
int n,q;
int edges_of_root[maxn];
void dfs(int u,int fa){
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u); 
        edges_of_root[u]+=edges_of_root[v]+1;   //u的子树上边的数目
        for(int j=min(edges_of_root[u],q);j;j--){
            for(int k=min(edges_of_root[v],j-1);k>=0;k--){
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[v][k]+edge[i].w);
            }
        }
    }
}

int main(){
    n=read();   q=read();
    for(int i=1;i<=n-1;i++){
        int from,to,w;
        from=read(); to=read(); w=read();
        addedge(from,to,w); addedge(to,from,w);
    }
    dfs(1,0);
    cout<<f[1][q];
    return 0;
}