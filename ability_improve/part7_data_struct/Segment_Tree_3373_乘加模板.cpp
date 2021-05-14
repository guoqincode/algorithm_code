//Re 0'
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

// void push_up(ll p){
//     tree[p].pre=(tree[p<<1].pre+tree[p<<1|1].pre)%mod;  //回溯的时候不要忘记mod
// }

void build(ll p,ll l,ll r){
    tree[p].l=l; tree[p].r=r; tree[p].mu=1; tree[p].add=0;
    if(l==r){
        tree[p].pre=a[l]%mod;
        return;
    }
    ll mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    //pre标记回溯
    // push_up(p);
    tree[p].pre=(tree[p*2].pre+tree[p*2+1].pre)%mod; 
}

void spread(int p){
    //从p到他的左右子树扩散懒标记 与最简单的只有加标记不同，这里有 乘和加 要考虑优先级
    tree[p*2].pre=(tree[p].mu*tree[p*2].pre+((tree[p*2].r-tree[p*2].l+1)*tree[p].add)%mod)%mod;
    tree[p*2+1].pre=(tree[p].mu*tree[p*2+1].pre+((tree[p*2+1].r-tree[p*2+1].l+1)*tree[p].add)%mod)%mod;

    tree[p*2].mu=(tree[p].mu*tree[p*2].mu)%mod;
    tree[p*2+1].mu=(tree[p].mu*tree[p*2+1].mu)%mod;

    tree[p*2].add=(tree[p].add+tree[p*2].add * tree[p].mu)%mod;
    // tree[p*2+1].mu=(tree[p].mu*tree[p*2+1].mu)%mod;
    tree[p*2+1].add=(tree[p].add+tree[p*2+1].add * tree[p].mu)%mod;

    tree[p].mu=1; tree[p].add=0;

}

void add(ll p,ll l,ll r,ll k){
    if(l<=tree[p].l&&r>=tree[p].r){
        tree[p].add=(tree[p].add+k)%mod;
        tree[p].pre=((tree[p].r-tree[p].l+1)+tree[p].pre)%mod;
        return;
    }
    spread(p);
    ll mid=(tree[p].l+tree[p].r)>>1;
    if(l<=mid) add(p*2,l,r,k);
    if(r>mid) add(p*2+1,l,r,k);
    tree[p].pre=(tree[p*2].pre+tree[p*2+1].pre)%mod;
}

void mul(ll p,ll l,ll r,ll k){
    if(l<=tree[p].l&&r>=tree[p].r){
        tree[p].add=(tree[p].add*k)%mod;
        tree[p].mu=(tree[p].mu*k)%mod;
        tree[p].pre=(tree[p].pre*k)%mod;
        return;
    }
    spread(p);
    // ll mid=(l+r)>>1;
    ll mid=(tree[p].l+tree[p].r)>>1;
    if(l<=mid) mul(p*2,l,r,k);
    if(r>mid) mul(p*2+1,l,r,k);
    tree[p].pre=(tree[p*2].pre+tree[p*2+1].pre)%mod;
}

ll query(ll p,ll l,ll r){
    if(tree[p].l>=l&&tree[p].r<=r){
        return tree[p].pre;
    }
    spread(p);
    // ll mid=()
    ll ans=0;
    ll mid=(tree[p].l+tree[p].r)>>1;
    if(l<=mid) ans=(ans+query(p*2,l,r))%mod; 
    if(r>=mid) ans=(ans+query(p*2+1,l,r))%mod;
    return ans;
}

int main(){
    n=read(); m=read(); mod=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);   //初始线段树简历完毕
    while(m--){
        ll op=read();
        if(op==1){
            ll x=read(),y=read(),k=read();
            mul(1,x,y,k);
        }else if(op==2){
            ll x=read(),y=read(),k=read();
            add(1,x,y,k);
        }else if(op==3){
            ll x=read(),y=read();
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}