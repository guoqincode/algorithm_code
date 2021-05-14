#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=201;
const int maxq=1e5;
int finish_time[maxn];
int dis[maxn][maxn];
// int cur_dis[maxn][maxn];
int n,m,q,query_times=1;
int query[maxq];
int pos=1;
void floyd(int t){
    while(finish_time[pos]<=t&&pos<=n){
        pos++;
    }
    int end=pos-1; //最后停下的位置 1-a 2-b 3-c ...
    // for(int i=1;i<=end;i++){
    //     for(int j=1;j<=end;j++){
    //         cur_dis[i][j]=dis[i][j];
    //     }
    // }
    for(int k=1;k<=end;k++){
        for(int i=1;i<=end;i++){
            for(int j=1;j<=end;j++){
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&finish_time[i]);
    fill(dis[0],dis[0]+maxn*maxn,INF);
    // fill(cur_dis[0],cur_dis[0]+maxn*maxn,INF);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        // cur_dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        dis[u+1][v+1]=dis[v+1][u+1]=d;
    }
    scanf("%d",&q);
    for(;query_times<=q;query_times++){
        int x,y;
        scanf("%d%d%d",&x,&y,&query[query_times]);
        //输出cur_dis[x+1][y+1];
        if(query_times==1){
            floyd(query[query_times]);
            if(dis[x+1][y+1]!=INF) cout<<dis[x+1][y+1]<<endl;
            else cout<<-1<<endl;
        }else if(query[query_times]==query[query_times-1]){
            if(dis[x+1][y+1]!=INF) cout<<dis[x+1][y+1]<<endl;
            else cout<<-1<<endl;
        }else{
            floyd(query[query_times]);
            if(dis[x+1][y+1]!=INF) cout<<dis[x+1][y+1]<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}