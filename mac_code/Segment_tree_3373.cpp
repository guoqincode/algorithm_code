//先乘后加的线段树
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long 
const int maxn=1e5+10;
ll a[maxn];
ll n,m,mod;
struct Tree{
    ll pre;
    ll l,r;
    ll mu;  //乘的懒标记
    ll add; //加的懒标记
}tree[maxn<<2+5];

inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ll)(ch-'0'); ch=getchar();}
    return x*f;  
}

void push_up(ll p){
    tree[p].pre=(tree[p<<1].pre+tree[p<<1|1].pre)%mod;  //回溯的时候不要忘记mod
}

void build(ll p,ll l,ll r){
    tree[p].l=l; tree[p].r=r; tree[p].mu=1; tree[p].add=0;
    if(l==r){
        tree[p].pre=a[l]%mod;
        return;
    }
    ll mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    //pre标记回溯
    push_up(p);
}

void spread(int p){
    //从p到他的左右子树扩散懒标记 与最简单的只有加标记不同，这里有 乘和加 要考虑优先级
    
}

int main(){
    n=read(); m=read(); mod=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);   //初始线段树简历完毕
    while(m--){

    }
}