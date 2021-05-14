//记忆化dfs 滑雪
#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int g[maxn][maxn],f[maxn][maxn],n,m,ans=0;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

inline int dfs(int x,int y){
    if(f[x][y]) return f[x][y];
    // f设置初始值
    f[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        // if(tx<1||tx>n||ty<1||ty>m) continue;        -->这样写60
        // if(g[tx][ty]>g[x][y]) continue;
        // dfs(tx,ty););
        // f[x][y]=max(f[x][y],f[tx][ty]+1
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&g[x][y]>g[tx][ty]){
            dfs(tx,ty);
            f[x][y]=max(f[x][y],f[tx][ty]+1);
        }
    }
    // ans=max(ans,f[x][y]);
    return f[x][y];
}

int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g[i][j]=read();
            // f[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    printf("%d",ans);
    return 0;
}