//p3146 区间dp 2048游戏
#include<bits/stdc++.h>
using namespace std;
const int maxn=255;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int n,dp[maxn][maxn];
int maxans=-1;
int main(){
    n=read(); 
    for(int i=1;i<=n;i++) dp[i][i]=read();
    for(int len=2;len<=n;len++){
        //枚举区间长度len从2到n
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                if(dp[i][k]==dp[k+1][j]&&dp[i][k]&&dp[k+1][j]){
                    dp[i][j]=max(dp[i][j],dp[i][k]+1);
                    maxans=max(maxans,dp[i][j]);
                }
            }
        }
    }
    printf("%d",maxans);
    return 0;
}