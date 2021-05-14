//树状数组模板
//树状数组 70'   线段树能结局的问题包含树状数组能解决的问题
#include<bits/stdc++.h>
using namespace std;
const int maxn=500001;
int a[maxn],tree[maxn];
int n,m;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int k){
    for(;x<=n;x+=lowbit(x)){
        tree[x]+=k;
    }
}
void build(){
    for(int i=1;i<=n;i++){
        // cin>>a[i];
        // tree[i]=i;
        update(i,a[i]);
    }
}
int query(int x){
    int ans=0;
    for(;x;x-=lowbit(x)){
        ans+=tree[x];
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build();
    for(int i=1;i<=m;i++){
        // int a,b,c;
        int q,x,y,z;
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d%d",&x,&y,&z);
            // change(1,x,y,k);
            for(int i=x;i<=y;i++) update(i,z);
        }else if(q==2){
            scanf("%d%d",&x,&y);
            cout<<query(y)-query(x-1)<<endl;
        }
        // scanf("%d%d%d",&a,&b,&c);
        // if(a==1) update(b,c);
        // else{
        //     printf("%d\n",query(c)-query(b-1));
        //     //cout<<query(c)-query(b-1)<<endl;
        // }
    }
    return 0;
}