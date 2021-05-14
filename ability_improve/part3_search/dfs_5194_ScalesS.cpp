//p5194 搜索＋剪枝
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1005;
ll a[maxn],sum[maxn];

inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int n,c;
ll ans;
inline void dfs(int cur,ll x){
    if(x>c) return;
    if(sum[cur-1]+x<=c){
        //剪枝: 前面的砝码都可以取走的话 直接取走就好
        ans=max(ans,sum[cur-1]+x);
        return;
    }
    ans=max(ans,x);
    for(int i=1;i<cur;i++){
        dfs(i,x+a[i]);
    }
    return;
}

int main(){
    n=read(); c=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=sum[i-1]+a[i];
    }
    dfs(n+1,0);
    printf("%lld",ans);
    return 0;
}