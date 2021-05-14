//p1122 树形dp 最大子树和
//样例过不了 但是却ac了
#include<bits/stdc++.h>
using namespace std;
const int maxn=16001;

struct Edge{
    int from;
    int to;
    int next;
}edge[maxn<<1];
int tot=0,head[maxn];

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline void addedge(int from,int to){
    edge[++tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

int n,a[maxn],f[maxn],ans=0;  //f[i]代表以i为根时候的最大子树和

inline void dfs(int u,int fa){
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=fa){
            //因为是建立的双向边 所以有可能指向父节点
            dfs(v,u);
            f[u]+=max(0,f[v]);
        }
    }
    ans=max(0,f[u]);
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),f[i]=a[i];
    for(int i=1;i<n;i++){
        int from,to;
        from=read(); to=read();
        addedge(from,to);
        addedge(to,from);
    }


    dfs(1,0);
    printf("%d",ans);
    return 0;
}
