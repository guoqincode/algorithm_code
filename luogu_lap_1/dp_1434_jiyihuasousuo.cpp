//记忆化搜索
#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int a[maxn][maxn],f[maxn][maxn];
int n,m,ans=-1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int dfs(int x,int y){
    if(f[x][y]) return f[x][y];
    f[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[x][y]>a[tx][ty]){
            dfs(tx,ty); //先求出来f[tx][ty]的值才能下面运算
            f[x][y]=max(f[tx][ty]+1,f[x][y]);
        }
    }
    return f[x][y];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cin>>a[i][j];
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans;
    return 0;
}