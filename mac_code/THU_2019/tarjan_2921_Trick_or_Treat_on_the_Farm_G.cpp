#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n;
int Next[maxn],ans[maxn];

inline int read(){
    int x=0,f=1; char ch = getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x = (x<<3) + (x<<1) + (ch-'0'); ch = getchar();};
    return x*f;
}

struct Edge{
    int from,to,next;
}edge[maxn];

int tot=0,head[maxn];
inline void addedge(int from,int to){
    tot++;
    edge[tot].from = from;
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot;
}

int sd[maxn],dfn[maxn],low[maxn],stac[maxn],vis[maxn];
int size_of_ring[maxn];
int tim = 0,top=0,col=0;
inline void tarjan(int x){
    low [x] = dfn[x] = ++tim;
    stac[++top] = x;
    vis[x] = 1;
    for(int i=head[x]; i ;i=edge[i].next){
        int v = edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[x] = min(low[x],low[v]);
        }else if(vis[v]){
            low[x] = min(low[x],low[v]);
        }
    }
    if(dfn[x] == low[x]){
        int y;
        col++;
        while(y=stac[top--]){
            sd[y] = col;
            // size_of_ring[col]++;
            vis[y] = 0;
            if(x==y) break;
        }
    }
    return;
}

inline void SearCh(int x,int nExt,int step){
    if(ans[nExt]!=0){
        ans[x] = ans[x] + step;
        return;
    }
    else SearCh(x,Next[nExt],step+1);
}

int main(){
    n = read();
    int temp;
    for(int i=1;i<=n;i++){
        temp = read();
        Next[i] = temp;
        if(Next[i] == i) ans[i] = 1;
        addedge(i,temp);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++) size_of_ring[sd[i]]++;
    for(int i=1;i<=n;i++){
        if(ans[i]==1) continue;
        if(size_of_ring[sd[i]]!=1) ans[i] = size_of_ring[sd[i]];
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0) SearCh(i,Next[i],1);
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}