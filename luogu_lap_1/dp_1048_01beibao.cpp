//01背包问题
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=101;
int t,n;
int val[maxn],weigh[maxn];
// int dp[maxn][maxn]; //dp[i][j]表示总容量为j的时候装完前i个 筐内的最大价值
int dp[1005];
int main(){
    scanf("%d%d",&t,&n);
    for(int i=1;i<=n;i++)   scanf("%d%d",&weigh[i],&val[i]);
    //二维dp会超时
    // for(int i=1;i<=n;i++){
    //     for(int j=t;j>=0;j--){
    //         if(j>=weigh[i]){
    //             dp[i][j]=max(dp[i-1][j-weigh[i]]+val[i],dp[i-1][j]);
    //         }else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    // printf("%d",dp[n][t]);
    for(int i=1;i<=n;i++){
        for(int j=t;j>=0;j--){
            if(j>=weigh[i]){
                dp[j]=max(dp[j-weigh[i]]+val[i],dp[j]);
            }
        }
    }
    printf("%d",dp[t]);
    return 0;
}