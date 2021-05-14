//线段树实现 某个区间内的异或和相加
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=300010;
int a[maxn];
struct Tree{
    int left,right;
    ll sum;
    ll add;
}t[maxn<<2];
int n,m,p,l,r;

inline void update_up(int p){
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}

inline void build(int p,int left,int right){   
    //建树
    t[p].left=left,t[p].right=right;
    if(left==right){
        t[p].sum=a[left];
        return;
    }
    int mid=(left+right)>>1;
    build(p<<1,left,mid);
    build(p<<1|1,mid+1,right);
    update_up(p);   //向上更新
}

inline void spread(int p,int len){
    //向下传递懒标记
    if(t[p].add){
        t[p<<1].add^=1;
        t[p<<1|1].add^=1;
        t[p<<1].sum=(len-(len>>1))-t[p<<1].sum;
        t[p<<1|1].sum=(len>>1)-t[p<<1|1].sum;
        t[p].add=0;
    }
}

inline ll query(int p,int L,int R){
    //LR是要查询的区间
    if(t[p].left>=L&&t[p].right<=R) return t[p].sum;
    spread(p,t[p].right-t[p].left+1);
    ll ans=0;
    int mid=(t[p].right+t[p].left)>>1;
    if(L<=mid) ans+=query(p<<1,L,R);
    if(R>mid) ans+=query(p<<1|1,L,R);
    return ans;
}
inline void change(int p,int L,int R){
    spread(p,t[p].right-t[p].left+1);
    if(t[p].left>=L&&t[p].right<=R){
        t[p].add^=1;
        t[p].sum=t[p].right-t[p].left+1-t[p].sum;
        return;
    }
    int mid=(t[p].right+t[p].left)>>1;
    if(L<=mid) change(p<<1,L,R);
    if(R>mid)  change(p<<1|1,L,R);
    update_up(p);
}

int main(){
    scanf("%d%d",&n,&m);
    //每次读入1位的整数
    for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&p,&l,&r);
        if(p==0) change(1,l,r);
        else printf("%lld\n",query(1,l,r));
    }
    return 0;
}