#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;      //设太大可能会溢出成为负数

const int maxn=205;
const int maxq=1e6;
int query[maxq];
int finish_time[maxn]; //村庄重建完成时间
int is_build[maxn];
int dis[maxn][maxn];    //未被破环时完成的村庄距离邻接矩阵
int cur_dis[maxn][maxn];   //记录当前查询时刻的邻接矩阵
int n,m,q,querynums=1;
int d[maxn],vis[maxn];
int from_nums[maxn],to_nums[maxn];
int pos;
int flag=0;     //为0的话说明全0

void dijkstra_flag(int st){
    memset(vis,0,sizeof(vis));
    fill(d+1,d+1+n,INF);
    d[st]=0;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){
            if(d[j]<MIN&&!vis[j]){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=1;
        for(int v=1;v<=n;v++){
            if(!vis[v]&&dis[u][v]){
                if(d[v]>d[u]+dis[u][v]){
                    d[v]=d[u]+dis[u][v];
                }
            }
        }
    }
    return;
}
void dijkstra(int st){
    memset(vis,0,sizeof(vis));
    fill(d+1,d+1+n,INF);
    d[st]=0;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){
            if(d[j]<MIN&&!vis[j]){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=1;
        for(int v=1;v<=n;v++){
            if(!vis[v]&&cur_dis[u][v]){
                if(d[v]>d[u]+cur_dis[u][v]){
                    d[v]=d[u]+cur_dis[u][v];
                }
            }
        }
    }
    return;
}

int querydis(int from,int to,int t){
    if(querynums==1){
        //第一次查询 无法判断利用之前的t递推当前的t
        pos=1;
        while(finish_time[pos]<=t&&pos<=n){
            is_build[pos]=1;
            pos++;
        }
        //所有修复好的村庄都已经标记好了
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]==INF){
                    continue;
                }
                if(i==j){
                    continue;
                }
                if(is_build[i]&&is_build[j]){
                    cur_dis[i][j]=dis[i][j];
                }
            }
        }
        dijkstra(from);
        if(d[to]==INF) return -1;
        else return d[to];
    }else if(t==query[querynums-1]){
        //时间不变  则当前的距离矩阵不用变
        if(from==from_nums[querynums-1]){
            //如果起始点再不变
            if(d[to]==INF) return -1;
            else return d[to];
        }else{
            dijkstra(from);
            if(d[to]==INF) return -1;
            else return d[to];
        }        
    }else{
        //t不是第一个 且和上一个不同
        while(finish_time[pos]<=t&&pos<=n){
            is_build[pos]=1;
            pos++;
        }
        //所有修复好的村庄都已经标记好了
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]==INF){
                    continue;
                }
                if(i==j){
                    continue;
                }
                // if(cur_dis[i][j]!=INF) continue;
                if(is_build[i]&&is_build[j]){
                    cur_dis[i][j]=dis[i][j];
                }
            }
        }
        // if(querynums==3){
        //     cout<<"3!!!!!!"<<endl;
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=n;j++){
        //             cout<<cur_dis[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }
        dijkstra(from);
        // if(querynums==3){
        //     for(int i=1;i<=n;i++) cout<<d[i]<<" ";
        //     cout<<endl;
        // }
        if(d[to]==INF) return -1;
        else return d[to];
    }
}

int main(){
    scanf("%d%d",&n,&m);
    fill(dis[0],dis[0]+maxn*maxn,INF);
    fill(cur_dis[0],cur_dis[0]+maxn*maxn,INF);  //初始化为所有的都不连通
    for(int i=1;i<=n;i++){
        scanf("%d",&finish_time[i]);
        if(finish_time[i]) flag=1;
    }
    for(int i=1;i<=m;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        dis[u+1][v+1]=dis[v+1][u+1]=d;
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        cur_dis[i][i]=0;
    }
    scanf("%d",&q);
    int ans;
    if(flag){
        for(;querynums<=q;querynums++){
            // int x,y;
            scanf("%d%d%d",&from_nums[querynums],&to_nums[querynums],&query[querynums]);
            ans=querydis(from_nums[querynums]+1,to_nums[querynums]+1,query[querynums]);
            cout<<ans<<endl;
        }
    }else{
        for(;querynums<=q;querynums++){
            // int x,y;
            scanf("%d%d%d",&from_nums[querynums],&to_nums[querynums],&query[querynums]);
            // int ans=querydis_flag(from_nums[querynums]+1,to_nums[querynums]+1,query[querynums]);
            dijkstra_flag(from_nums[querynums]+1);
            if(d[to_nums[querynums]+1]!=INF) ans=d[to_nums[querynums]+1];
            else ans=-1;
            cout<<ans<<endl;
        }
    }
    return 0;
}