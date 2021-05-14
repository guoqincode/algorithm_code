//p1613 图dp 跑路
//beizeng + dp
#include<bits/stdc++.h>
using namespace std;
const int maxn=51;
int dis[maxn][maxn];
int can_to[maxn][maxn][65];
int n,m;
int inf=0x3f3f3f3f;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    n=read(); m=read();
    // fill(dis,dis+maxn*maxn,inf);
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++) dis[i][j]=inf;  
        //记得设dis初值 不设只有10'
    }
    for(int i=1;i<=m;i++){
        int u,v;
        u=read(); v=read();
        dis[u][v]=1;
        can_to[u][v][0]=1;  // u->v 2^0可到达
    }


    //对dis 和 can_to 做预处理
    for(int k=1;k<=64;k++){
        for(int i=1;i<=n;i++){
            for(int t=1;t<=n;t++){
                for(int j=1;j<=n;j++){
                    if(can_to[i][t][k-1]&&can_to[t][j][k-1]){
                        //利用倍增的思想
                        dis[i][j]=1;
                        can_to[i][j][k]=1;
                    }
                }
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }    
    cout<<dis[1][n];
    return 0;
}