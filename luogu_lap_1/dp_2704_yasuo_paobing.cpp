//p2704 炮兵阵地 状态压缩dp
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
int n,m,maxstate,g[101][11];
//max m=10  (11 1111 1111)2=(1023)10
// bool state[1024];
int f[101]; //记录每一行的情况对应的十进制值

int dp[1024][1024][3];      //dp[l][s][i] 当前状态为s  上一行状态为l  考虑到了第几行

int sum[1024];  //记录每一个状态中有多少1
int getsum(int x){
    //统计x二进制数中1的数目
    int res=0;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}

int main(){
    n=read(); m=read();
    maxstate=(1<<m);    //对应的最多种情况
    char tempch;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // scanf("%c",&tempch);
            cin>>tempch;
            if(tempch=='H') g[i][j]=1;  
            // cout<<i<<" "<<j<<endl;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) f[i]=(f[i]<<1)+g[i][j]; //状态和f[i] &  !=0 代表该状态碰到了山丘，不合适
    }
    // for(int i=0;i<n;i++) cout<<f[i]<<endl;
    for(int i=0;i<maxstate;i++) sum[i]=getsum(i);
    // for(int i=0;i<maxstate;i++) cout<<sum[i]<<endl;
    //初始化dp
    for(int s=0;s<maxstate;s++) dp[0][s][0]=sum[s];
    for(int L=0;L<maxstate;L++){
        for(int S=0;S<maxstate;S++){
			if(!(L&S || L&f[0] || S&f[1] || (L&(L<<1)) || (L&(L<<2)) || (S&(S<<1)) || (S&(S<<2))))	//谜之一长串特判
				dp[L][S][1]=sum[S]+sum[L];
        }
    }
    
    for(int i=2;i<=n;i++){
        for(int L=0;L<maxstate;L++){
            if(L&f[i-1] || (L&(L<<1)) || (L&(L<<2))) continue;
            for(int S=0;S<maxstate;S++){
                if(S&f[i] || (S&(S<<1)) || (S&(S<<2)) || L&S) continue;
                for(int FL=0;FL<maxstate;FL++){
                    if(FL&L || FL&S || FL&f[i-2] || (FL&(FL<<1)) || (FL&(FL<<2)))	continue;
                    dp[L][S][i%3]=max(dp[L][S][i%3],dp[FL][L][(i-1)%3]+sum[S]);  //只需要用到当前行 上一行 上上一行 所以用滚动数组的形式实现	
                }
            }
        }
    }
    int ans=0;
    for(int L=0;L<maxstate;L++){
        for(int S=0;S<maxstate;S++){
            ans=max(ans,dp[L][S][(n-1)%3]);
        }
    }
    cout<<ans;
    return 0;
}