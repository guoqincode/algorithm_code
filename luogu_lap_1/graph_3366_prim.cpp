#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=5001;
const int maxm=500005;
int d[maxn],vis[maxn],head[maxn];
int num_edges=0;
int ans=0;
int n,m;
struct Edge{
    int to;
    int dis;
    int next;
}edge[maxm];

inline void addegde(int from,int to,int dis){
    num_edges++;
    edge[num_edges].to=to;
    edge[num_edges].next=head[from];
    edge[num_edges].dis=dis;
    head[from]=num_edges;
}

inline void prim(int st){
    fill(d+1,d+1+n,INF);
    d[st]=0;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){
            if(d[j]<MIN&&vis[j]==0){
                u=j,MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=1;   //加入到s集合中
        ans+=d[u];

        for(int x=head[u];x;x=edge[x].next){
            int y=edge[x].to;
            if(vis[y]==0&&edge[x].dis<d[y]){
                d[y]=edge[x].dis;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        addegde(a,b,c);
        addegde(b,a,c);
    }
    prim(1);
    cout<<ans;
    return 0;
}