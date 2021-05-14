//只有第一行可以建造蓄水厂
//犯的错误 1.要在dfs之前初始化好l 和 r  2.要初始 l 全为inf r全为0  最后一行要单独初始化
#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
const int inf=0x3f3f3f3f;
int n,m;
int h[maxn][maxn],f[maxn][maxn],vis[maxn][maxn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int leftt[maxn][maxn],rightt[maxn][maxn];
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(tx<1||tx>n||ty<1||ty>m) continue;
        if(h[tx][ty]>=h[x][y]) continue;
        if(!vis[tx][ty]) dfs(tx,ty);    //初步dfs完成

        //最难的那部分是 我们怎么确定最需要的最小的蓄水站数量
        //易证:每一个第一层节点所覆盖的最后一层节点都是连续的
        leftt[x][y]=min(leftt[x][y],leftt[tx][ty]);
        rightt[x][y]=max(rightt[x][y],rightt[tx][ty]);
    }
}

int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) h[i][j]=read();
    }

    //!!在dfs之前就要初始化完成
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) leftt[i][j]=inf,rightt[i][j]=0;   //初始化
    }
    for(int i=1;i<=m;i++) leftt[n][i]=rightt[n][i]=i;

    //首先考虑第一列全部修建蓄水场情况下
    for(int i=1;i<=m;i++){
        if(!vis[1][i]) dfs(1,i); 
    }
    int cnt=0;

    //处理有没被覆盖到的情况
    for(int j=1;j<=m;j++){
        if(!vis[n][j]) cnt++;
    }
    if(cnt){
        printf("0\n");
        printf("%d",cnt);
        return 0;
    }

    

    int lefttt=1;
    while(lefttt<=m){
        int maxr=0; //最后的右端点是最大的(在左端点小于原始左端点的点中找)
        for(int i=1;i<=m;i++){
            if(leftt[1][i]<=lefttt){
                maxr=max(maxr,rightt[1][i]);
            }
        }
        cnt++;
        // printf("%d\n",cnt);   //一直卡在这里循环了
        lefttt=maxr+1;
    }

    printf("1\n");
    printf("%d",cnt);
    return 0;
}