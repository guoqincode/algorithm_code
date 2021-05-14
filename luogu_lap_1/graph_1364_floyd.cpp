#include<bits/stdc++.h>
using namespace std;
const int INF=100000000;
const int maxn=110;
int dis[maxn][maxn];
int weight[maxn]={0};
int n;

void floyd(){
    //枚举中间节点k
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

int main(){
    cin>>n;
    fill(dis[0],dis[0]+maxn*maxn,INF);  //*
    for(int i=1;i<=n;i++){
        int w,u,v;
        cin>>w>>u>>v;
        weight[i]=w;
        if(u) dis[u][i]=dis[i][u]=1;
        if(v) dis[v][i]=dis[i][v]=1;
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    floyd();
    int minv=INF;
    for(int i=1;i<=n;i++){
        //从第一个点开始枚举
        int tempv=0;
        for(int j=1;j<=n;j++){
            tempv+=dis[j][i]*weight[j];
        }
        minv=min(tempv,minv);
    }
    cout<<minv;
    return 0;
}