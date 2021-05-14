#include<iostream>
// #include<math>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m;
int dp[maxn][21];
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    n=read(); m=read();
    // cin>>n>>m;
    for(int i=1;i<=n;i++) dp[i][0]=read();
    for(int k=1;k<=21;k++){
        for(int i=1;i+(1<<k)-1<=n;i++){
            dp[i][k]=min(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
        }
    }
    int a,b;
    for(int i=1;i<=m;i++){
        a=read(); b=read();
        // cin>>a>>b;
        int len=log2(b-a+1);
        printf("%d ",min(dp[a][len],dp[b-(1<<len)+1][len]));
    }
    return 0;
}