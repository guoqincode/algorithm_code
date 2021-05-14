#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=100000000;   //无穷大
int G[maxn][maxn];  //邻接矩阵
bool vis[maxn]={false}; //访问矩阵
int d[maxn];    //最短距离
int teammates[maxn]={0};    //每个城市有多少人->点权
int N,M,source,destination;
int nums_path[maxn]={0},w[maxn]={0};    //最短路径条数 点权
void Dijkstra(int s){
    //s为起点
    fill(d,d+maxn,INF);
    // memset(nums_path,0,sizeof(nums_path));
    // memset(w,0,sizeof(w));
    d[s]=0;
    w[s]=teammates[s];
    nums_path[s]=1;
    for(int i=0;i<N;i++){
        //循环完所有节点

        //找到最小的u
        int u=-1,MIN=INF;
        for(int j=0;j<N;j++){
            if(vis[j]==false && d[j]<MIN){
                //从未被访问的节点中找最小路径的
                // cout<<"vis[j]=="<<vis[j]<<" and "<<"d[j]=="<<d[j]<<endl;
                u=j;
                MIN=d[j];
            }
            //else{
            //     cout<<"!vis[j]=="<<vis[j]<<" and "<<"d[j]=="<<d[j]<<endl;
            // }
        }
        //cout<<"hi "<<u<<endl;
        if(u==-1) return;   //未找到 说明剩下的和s不连通
        vis[u]=true;


        //更新
        for(int v=0;v<N;v++){
            if(vis[v]==false&&G[u][v]!=0){
                if(d[u]+G[u][v]<d[v]){
                    //以u为中介能使d[v]变小
                    d[v]=d[u]+G[u][v];
                    w[v]=teammates[v]+w[u];     //计算点权
                    nums_path[v]=nums_path[u];  //路径数
                }else if(d[u]+G[u][v]==d[v]){
                    if(teammates[v]+w[u]>w[v]){
                        w[v]=teammates[v]+w[u];     //计算最大点权
                    }
                    //最短路径有多条
                    nums_path[v]+=nums_path[u];     //有多个相同的最短路径时 相加
                }
            }
        }

        
    }
}
int main(){
    cin>>N>>M>>source>>destination;
    for(int i=0;i<N;i++){
        cin>>teammates[i];  //读入点权
    }
    // for(int i=0;i<N;i++){
    //     cout<<teammates[i]<<" ";  //读入点权
    // }
    // cout<<endl;
    for(int i=0;i<M;i++){
        int temp_s,temp_d,dis;
        cin>>temp_s>>temp_d>>dis;
        G[temp_s][temp_d]=G[temp_d][temp_s]=dis;    //->无向边
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<G[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //要求输出源点到目的点的最短距离的条数  并输出具有最大点权的最短路径的点权
    Dijkstra(source);
    cout<<nums_path[destination]<<" "<<w[destination]<<endl;
    // for(int i=0;i<N;i++){
    //     cout<<nums_path[i]<<" "<<w[i]<<" "<<d[i]<<endl;
    // }
    // for(int i=0;i<N;i++){
    //     cout<<d[i]<<endl;
    // }
    // for(int i=0;i<N;i++){
    //     cout<<vis[i]<<endl;
    // }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<G[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
