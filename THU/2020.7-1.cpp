//重写一下20年清华夏令营机试题目
//第一题 签到题
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+5;
ll a[maxn];
int n,m;

inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    scanf("%d%d",&n,&m);
    char op;
    ll x,y;
    for(int i=1;i<=m;i++){
        scanf("%c",&op);
        x=read(); y=read();
        if(op=='A'){
            //增加的情况
            a[x]+=y;
            if(a[x]>1e9) a[x]=1e9;
        }else if(op=='D'){
            a[x]-=y;
            if(a[x]<0) a[x]=0;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",a[i]);
    }
    return 0;
}