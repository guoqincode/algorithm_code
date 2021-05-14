//线段树板子
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn=100010;
int a[maxn+2];
int n,m;
struct Tree{
    int left,right;
    ll pre;
    ll lazy;   //懒标记
}tree[maxn*4+2];

// inline int read(){
//     int x=0,f=1; char ch=getchar();
//     while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
//     while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
//     return x*f;
// }

inline int push_up(int p){
    tree[p].pre=tree[p*2].pre+tree[p*2+1].pre;
}

inline void build(int p,int l,int r){
    //建立起最初始的线段树
    tree[p].left=l; tree[p].right=r;
    if (l==r){
        tree[p].pre=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);  //左子树为[l,mid]
    build(p*2+1,mid+1,r);
    // push_up(p); //回溯求区间值
    tree[p].pre=tree[p*2].pre+tree[p*2+1].pre;

}

inline void spread(int p){
    //只有在子区间有用的时候才会下放lazy 这样可以最小的节省计算资源
    if(tree[p].lazy){
        tree[p*2].pre+=(tree[p*2].right-tree[p*2].left+1)*tree[p].lazy;
        tree[p*2+1].pre+=(tree[p*2+1].right-tree[p*2+1].left+1)*tree[p].lazy;
        tree[p*2].lazy+=tree[p].lazy;
        tree[p*2+1].lazy+=tree[p].lazy;
        tree[p].lazy=0;
    }
}

inline void change(int p,int x,int y,int k){
    //[x,y]上的每一个数都加上k
    if(x<=tree[p].left&&y>=tree[p].right){
        //覆盖住了
        tree[p].pre+=(tree[p].right-tree[p].left+1)*(ll)k;
        tree[p].lazy+=k;
        return ;
    }

    //! 如果没有覆盖 就要向下寻找 下放懒标记
    spread(p);

    int mid=(tree[p].left+tree[p].right)>>1;
    if(x<=mid) change(p*2,x,y,k);
    if(y>mid) change(p*2+1,x,y,k);

    //!
    // push_up(p);
    tree[p].pre=tree[p*2].pre+tree[p*2+1].pre;

}

inline ll query(int p,int x,int y){
    if(x<=tree[p].left&&y>=tree[p].right){
        return (ll)tree[p].pre;
    }

    //!
    spread(p);

    ll ans=0;
    int mid=(tree[p].left+tree[p].right)>>1;
    if(x<=mid) ans+=query(p*2,x,y);
    if(y>=mid+1) ans+=query(p*2+1,x,y);
    return ans;
}



// int main(){
//     n=read(); m=read();
//     for(int i=1;i<=n;i++) a[i]=read();
//     build(1,1,n);
//     int op,x,y,k;
//     while(m--){
//         op=read();
//         if(op==1){
//             //[x,y]每一个数都加上k
//             x=read(); y=read(); k=read();
//             change(1,x,y,k);
//         }else{
//             x=read(); y=read();
//             // cout<<query(1,x,y)<<endl;
//             printf("%lld\n",query(1,x,y));
//         }
//     }
//     return 0;
// }

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int q,x,y,k;
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d%d",&x,&y,&k);
            change(1,x,y,k);
        }else if(q==2){
            scanf("%d%d",&x,&y);
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}