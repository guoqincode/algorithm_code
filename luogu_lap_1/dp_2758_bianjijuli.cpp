//编辑距离
#include<bits/stdc++.h>
using namespace std;
const int maxn=2001;
int dp[maxn][maxn];     //dp[i][j]代表a的前i个和b的前j个的最小编辑距离
char a[maxn],b[maxn];
int asize=0,bsize=0;

int main(){
    scanf("%s",a);
    scanf("%s",b);
    asize=strlen(a); bsize=strlen(b);
    for(int i=0;i<=asize;i++) dp[i][0]=i;   //初始化边界
    for(int j=0;j<=bsize;j++) dp[0][j]=j;
    for(int i=1;i<=asize;i++){
        for(int j=1;j<=bsize;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            //分别对应删添替
        }
    }
    printf("%d",dp[asize][bsize]);
    return 0;
}