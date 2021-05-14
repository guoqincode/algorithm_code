//p1441 砝码称重
//先dfs 再dp
//背包问题 背包压缩问题还不太明白
#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int n,m;
int a[25];
int thro[25];

int f[2500],res,ans,tot;
inline void dp(){
    memset(f,0,sizeof(f)); f[0]=1; ans=0; tot=0;
    for(int i=0;i<n;i++){
        if(thro[i]) continue;
        for(int j=tot;j>=0;j--) if(f[j]&&!f[j+a[i]]) f[j+a[i]]=1,ans++;
        tot+=a[i];
    }
    res=max(ans,res);
}

inline void dfs(int cur,int now){
    //cur代表当前扫过几个元素了 now代表当前舍弃多少元素了
    if(now>m) return;
    if(cur==n){
        if(now==m) dp();
        return;
    }
    dfs(cur+1,now); //选择当前元素

    thro[cur]=1;
    dfs(cur+1,now+1); //舍弃当前元素
    thro[cur]=0;    //回溯

}


int main(){
    n=read(); m=read();
    for(int i=0;i<n;i++) a[i]=read();
    dfs(0,0);
    cout<<res;
    return 0;
}