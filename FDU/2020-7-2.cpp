//二维dp  找出最大的正方形子矩阵 dp入门
#include<bits/stdc++.h>
using namespace std;
const int maxn=101,maxm=101;
int ans=0;
int g[maxn][maxm],dp[maxn][maxm];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]){
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;  //找到核心递推式就行了
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans;
    return 0;
}