//图中的边权有负值，求最常路-->把每个权值变成负数，求最小值，再输出最小值的相反数就是最大值
//spfa算法
#include<bits/stdc++.h>
using namespace std;
const int maxn=1501;
const int INF=100000000;
typedef struct{
    int v;  //边指向的顶点
    int dis;    //边权   -->增加了边权的话，邻接表不能只放节点，还要放边权，否则就要开一个大的二维数组
}Node;
int n,m;
vector<Node>adj[maxn];
int vis[maxn]={0},d[maxn];


void spfa(){
    fill(d,d+maxn,INF);
    queue<int>q;
    q.push(1);
    vis[1]=1;
    d[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            int dis=adj[u][j].dis;
            if(d[u]+dis<d[v]){
                d[v]=d[u]+dis;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,tempdis;
        cin>>a>>b>>tempdis;
        Node node;
        node.v=b;
        node.dis=-tempdis;
        adj[a].push_back(node);
    }
    spfa();
    //for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    if(d[n]==INF){
        cout<<-1;
    }else cout<<-d[n];
    return 0;
}
