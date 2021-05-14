//p1879 状态压缩  求一共有多少种种植方案
#include<bits/stdc++.h>
using namespace std;
const int mod=1e8;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int m,n,field[13][13],fiel[13];
int dp[13][4096];  // max = (1111 1111 1111)2= (4095)10
bool state[4096];
int main(){
    m=read(); n=read();
    int maxsize=(1<<n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) field[i][j]=read();
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) fiel[i]=(fiel[i]<<1)+field[i][j]; //记录下每一行的土壤状态对应的十进制数
    }
    // for(int i=1;i<=m;i++) printf("%d\n",fiel[i]);

    for(int i=0;i<(1<<n);i++) state[i] = ((i&(i<<1))==0) && ((i&(i>>1))==0);    //记录下来每一个状态是否可行   注意这里的括号顺序

    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<maxsize;j++){
            if(state[j]&&((j&fiel[i])==j)){
                //找到某个状态 这个状态本身就可行
                for(int k=0;k<maxsize;k++){
                    //在这里是搜索了所有状态 有的状态再第i-1行没有 =0 只需遍历所有状态即可
                    if((j&k)==0) dp[i][j] = (dp[i][j]+dp[i-1][k]) % mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++) ans = (ans + dp[m][i]) % mod;
    printf("%d",ans);
    return 0; 
}