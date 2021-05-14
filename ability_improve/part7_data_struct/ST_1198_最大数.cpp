// #include<bits/stdc++.h>
// using namespace std;
// const int maxn=2e5+10;
// int m,mod,t=0;
// int tot=0;
// char ch;
// int n;
// int dp[maxn][21];
// inline int read(){
//     int x=0,f=1; char ch=getchar();
//     while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
//     while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
//     return x*f;
// }

// inline void change(){
//     //添加操作  t是最近一次查询的结果
//     n=(n+t)%mod;
//     tot++;
//     dp[tot][0]=n;
//     //更新涉及到的区间内最小值  dp[i][j]表示[i..]
//     for(int i=1;tot-(1<<i)>=0;i++) dp[tot][i]=max(dp[tot][i-1],dp[tot-(1<<(i-1))][i-1]);
// }

// inline int query(int l,int r){
//     if(r==l) return dp[r][0];
//     int len=(r-l+1);
//     return max(dp[r][len],dp[l+(1<<len)-1][len]);
// }

// int main(){
//     m=read(); mod=read();
//     for(int i=1;i<=m;i++){
//         scanf("%c",&ch); n=read();
//         if(ch=='A'){
//             change();        
//         }else if(ch=='Q'){
//             //输出最后n个数的最大数
//             t=query(tot-n+1,tot);
//             printf("%d\n",t);
//         }
//     }
//     return 0;
// }

#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
ll a[200001],f[200001][21],t,D;
int n,m;
bool flag;
void change(int u){  //用change函数来进行修改
    f[u][0]=a[u];
    for(int i=1;u-(1<<i)>=0;i++) f[u][i]=max(f[u][i-1],f[u-(1<<(i-1))][i-1]);
}
ll find(int x,int y){
    double t=log(y-x+1)/log(2);
    int K=t;
    return max(f[y][K],f[x+(1<<K)-1][K]);
}
int main(){
    memset(f,0,sizeof(f));
    scanf("%d%lld",&m,&D);
    for (int i=1;i<=m;i++){
        char c;
        cin>>c;
        ll x;
        if (c=='A'){  //根据题面的操作，注意细节。
            scanf("%lld",&x);
            a[++n]=(x+t)%D;
            change(n);
        }else{
            int L; scanf("%d",&L);
            ll ans;
            if (L==1){
                printf("%lld\n",a[n]);
                t=a[n]; continue;
            }
            ans=find(n-L+1,n);
            printf("%lld\n",ans); t=ans;
        }
    }
    return 0;
}