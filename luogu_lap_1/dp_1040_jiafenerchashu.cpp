//p1040 dp 加分二叉树
//dp[i][j]代表 中序a[i...j]中产生的最大加分二叉树
//所以 dp[i][j]=max(dp[i][k-1]*dp[k+1][j]+a[k])
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
long long n,dp[maxn][maxn],root[maxn][maxn];
inline long long read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){ x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline void in(int left,int right){
    if(left>right) return ;
    printf("%lld ",root[left][right]);
    if(left==right) return;
    in(left,root[left][right]-1);
    in(root[left][right]+1,right);
}

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        dp[i][i]=read();
        root[i][i]=i;
    }
    for(int len=1;len<n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            dp[i][j]=dp[i][i]+dp[i+1][j];   //首先假设没有左子树
            root[i][j]=i;
            for(int k=i+1;k<j;k++){
                if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+dp[k][k]){
                    dp[i][j]=dp[i][k-1]*dp[k+1][j]+dp[k][k];
                    root[i][j]=k;
                }
            }
        }
    }
    // printf("%lld",dp[1][n]);
    cout<<dp[1][n]<<endl;
    in(1,n);
    return 0;
}