#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
const int INF=(int)(pow(2,31)-1);
int n,m,st;
int gra[maxn][maxn];    //邻接矩阵写法会有三十分的MLE
typedef struct{
    int node;
    int dis;
}Edge;
vector<Edge>adj[maxn];
int d[maxn],vis[maxn];

void dijkstra(int st){
    fill(d,d+maxn,INF);
    memset(vis,0,sizeof(vis));
    d[st]=0;
    // vis[st]=1;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&d[j]<MIN){
                u=j,MIN=d[j];
            }
        }
        if(u==-1) return;   //找完了
        //u是找出的距离最短的点
        vis[u]=1;   //访问u
        //更新剩下的未访问的d[v]
        for(int v=1;v<=n;v++){
            if(!vis[v]&&gra[u][v]){
                //v未被访问且v可达
                if(d[u]+gra[u][v]<d[v]){
                    d[v]=d[u]+gra[u][v];
                }
            }
        }
    }
    return ;
}

void dijkstra_link(int st){
    fill(d,d+maxn,INF);
    memset(vis,0,sizeof(vis));
    d[st]=0;
    // vis[st]=1;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&d[j]<MIN){
                u=j,MIN=d[j];
            }
        }
        if(u==-1) return;   //找完了
        //u是找出的距离最短的点
        vis[u]=1;   //访问u
        //更新剩下的未访问的d[v]
        // for(int v=1;v<=n;v++){
        //     if(!vis[v]&&gra[u][v]){
        //         //v未被访问且v可达
        //         if(d[u]+gra[u][v]<d[v]){
        //             d[v]=d[u]+gra[u][v];
        //         }
        //     }
        // }
        for(int v=0;v<adj[u].size();v++){
            if(!vis[adj[u][v].node]){
                if(d[u]+adj[u][v].dis<d[adj[u][v].node]){
                    d[adj[u][v].node]=d[u]+adj[u][v].dis;
                }
            }
        }
    }
    return ;
}

void addedge(int u,int v,int dis){
    if(u==v) return;
    Edge edge;
    int flag=0;
    edge.node=v,edge.dis=dis;
    if(adj[u].empty()){
        adj[u].push_back(edge);
        return;
    }else{
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i].node==v){
                if(dis<adj[u][i].dis){
                    adj[u][i].dis=dis;
                    flag=1;
                    return;
                }else{
                    flag=2;
                    break;
                }
            }
        }
    }
    if(flag==0) adj[u].push_back(edge);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>st;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        // gra[u][v]=w;
        // if(w<gra[u][v]) gra[u][v]=w;
        // if(gra[u][v]==0) gra[u][v]=w;
        // else if(w<gra[u][v]) gra[u][v]=w;
        addedge(u,v,w);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j].node<<" "<<adj[i][j].dis<<"; ";
    //     }
    //     cout<<endl;
    // }
    // dijkstra(st);
    dijkstra_link(st);
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    return 0;
}