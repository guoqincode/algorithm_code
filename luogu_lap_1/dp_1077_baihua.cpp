//摆花问题
//爆搜30' 8.41s 648kb ->记忆化搜索100' 29ms 640kb ->dp 27ms 624kb -> dp优化 滚动数组 26ms 656kb
#include<bits/stdc++.h>
using namespace std;
const int maxn=101,maxm=101;
const int mod=1000007;
int n,m,a[maxn];
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){ x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
// int d[maxn][maxm];
// int dfs(int x,int k){
//     if(k>m) return 0;
//     if(k==m) return 1;
//     if(x==n+1) return 0;
//     if(d[x][k]) return d[x][k];

//     int ans=0;
//     for(int i=0;i<=a[x];i++) ans=(ans+dfs(x+1,k+i))%mod;
//     d[x][k]=ans;
//     return ans;
// }
// int dfs(int x,int k){
    
//     if(k>m) return 0;
//     if(k==m) return 1;
//     if(x==n+1) return 0;
//     int ans=0;
//     for(int i=0;i<=a[x];i++) ans=(ans+dfs(x+1,k+i))%mod;
//     return ans;
// }

// int dp[maxn][maxn]; //dp[i][j]= dp[i-1][j-k] k=0~a[i]
int dpy[2][maxn],t=0; //每一次只有dp[i] dp[i-1]有用 所以可以压成2
int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    // printf("%d\n",dfs(1,0));
    // dp[0][0]=1;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         for(int k=0;k<=min(j,a[i]);k++){
    //             dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
    //         }
    //     }
    // }
    // printf("%d",dp[n][m]);
    dpy[0][0]=1;
    for(int i=1;i<=n;i++){
        t=1-t;
        for(int j=0;j<=m;j++){
            dpy[t][j]=0;
            for(int k=0;k<=min(j,a[i]);k++){
                dpy[t][j]=(dpy[t][j]+dpy[1-t][j-k])%mod;
            }
        }
    }
    printf("%d",dpy[t][m]);
    return 0;
}
