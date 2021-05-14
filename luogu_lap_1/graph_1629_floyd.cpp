#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
const int INF=(int)(pow(2,31)-1);
int gra[maxn][maxn];
int n,m;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(gra[i][k]!=INF&&gra[k][j]!=INF&&gra[i][k]+gra[k][j]<gra[i][j]){
                    gra[i][j]=gra[i][k]+gra[k][j];
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    fill(gra[0],gra[0]+maxn*maxn,INF);
    for(int i=1;i<=m;i++){
        int u,v,dis;
        cin>>u>>v>>dis;
        if(u==v) continue;
        if(gra[u][v]==INF) gra[u][v]=dis;
        else if(gra[u][v]&&dis<gra[u][v]) gra[u][v]=dis;
    }
    floyd();
    int sum=0;
    for(int i=2;i<=n;i++){
        sum=sum+gra[1][i]+gra[i][1];
    }
    cout<<sum;
    return 0;
}