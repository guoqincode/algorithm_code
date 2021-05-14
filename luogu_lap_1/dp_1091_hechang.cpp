//p1091 合唱队形
//两个方向的最长升序列
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,a[maxn],ans=0;
int dp[2][maxn];    //0正方向 1反方向
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){ x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    n=read();
    a[0]=a[n+1]=0;  //两个方向的初始点初始化
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]) dp[0][i]=max(dp[0][i],dp[0][j]+1);
        }
    }
    for(int i=n;i;i--){
        for(int j=n+1;j>i;j--){
            if(a[i]>a[j]) dp[1][i]=max(dp[1][i],dp[1][j]+1);
        }
    }
    for(int i=1;i<=n;i++) ans=max(dp[0][i]+dp[1][i]-1,ans);
    printf("%d",n-ans);
    return 0;
}
