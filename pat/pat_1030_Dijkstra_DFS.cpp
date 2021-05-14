#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=100000000;
int G[maxn][maxn]={0},cost[maxn][maxn]={0}; //邻接矩阵 消耗矩阵
int d[maxn]={INF};
bool vis[maxn]={false};
vector<int>pre[maxn];
vector<int>path,temppath;   //最优路径和临时路径
int n,m,st,de;
int mincost=INF;
void Dijkstra(int s){
    fill(d,d+maxn,INF); //遗忘了导致第一遍没过
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        // cout<<u<<endl;
        vis[u]=true;
        for(int v=0;v<n;v++){

            //核心代码
            if(vis[v]==false&&G[u][v]!=0){
                //v未被访问过且 u可达v
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }


        }
    }
}

void DFS(int v){
    //访问到了节点v
    //递归边界
    if(v==st){
        //到达了起点
        temppath.push_back(v);
        //计算当前的第二标尺值
        int value;
        for(int i=temppath.size()-1;i>0;i--){
            int id=temppath[i],idnext=temppath[i-1];
            value+=cost[id][idnext];
        }
        if(value<mincost){
            mincost=value;
            path=temppath;
        }
        temppath.pop_back();
        return;
    }
    //递归式
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    temppath.pop_back();
}
int main(){
    cin>>n>>m>>st>>de;
    for(int i=0;i<m;i++){
        int temp_s,temp_d,temp_g,temp_c;
        cin>>temp_s>>temp_d>>temp_g>>temp_c;
        G[temp_s][temp_d]=G[temp_d][temp_s]=temp_g;
        cost[temp_s][temp_d]=cost[temp_d][temp_s]=temp_c;
    }
    Dijkstra(st);
    DFS(de);
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    cout<<d[de]<<" "<<mincost;
    return 0;
}