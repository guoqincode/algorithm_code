//st表模板 静态区间最大值
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int dp[maxn][21];   //dp[i][j]表示从第i个开始的2^j个数之间最大值 即max(i,...i+2^j-1)
int n,m;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) dp[i][0]=read();
    for(int k=1;k<=21;k++){
        for(int i=1;i+(1<<k)-1<=n;i++){
            dp[i][k]=max(dp[i][k-1],dp[i+(1<<k-1)][k-1]);
        }
    }
    int a,b;
    for(int i=1;i<=m;i++){
        a=read(); b=read();
        //query
        int k=log2(b-a+1); //k=log2(len)
        printf("%d\n",max(dp[a][k],dp[b-(1<<k)+1][k]));   //x+2^k-1=b-->x=b-2^k+1
    }
    return 0;
}