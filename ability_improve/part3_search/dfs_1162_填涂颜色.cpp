//p1162 dfs  填涂颜色  从四周开始dfs 碰到1就是墙
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=31;
int g[maxn][maxn],f[maxn][maxn];

inline void dfs(int i,int j){
    if(i<1||i>n||j<1||j>n||g[i][j]) return;
    g[i][j]=1;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
            f[i][j]=g[i][j];
        }
    }
    for(int i=1;i<=n;i++) dfs(i,1),dfs(i,n),dfs(1,i),dfs(n,i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i][j]) printf("1 ");
            else if(g[i][j]) printf("0 ");
            else printf("2 ");
        }
        printf("\n");
    }
    return 0;
}
