//环形dp p1063 能量项链
#include<bits/stdc++.h>
using namespace std;
const int maxn=210; //环形 开2*n的空间
int a[maxn];
int dp[maxn][maxn]; //dp[i][j]代表[i...j]区间的最大值
//dp[i][j]=max(dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1])
int n;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),a[i+n]=a[i];
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=2*n;i++){  //i<=n 50' -> i+len<=2*n 100'
            //从i=1开始作为开头到i=n开始作为结束
            int j=i+len;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
}

