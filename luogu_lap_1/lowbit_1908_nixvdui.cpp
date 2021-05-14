#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;

struct Nums{
    int val;
    int num;
}nums[maxn];

bool cmp(Nums a,Nums b){
    if(a.val==b.val) return a.num<b.num;
    else return a.val<b.val;
}

int rank_point[maxn]; //记录每个节点的排名
int tree[maxn];
int n;
long long ans=0;

inline int lowbit(int x){
    return x&(-x);
}

inline void update(int x,int k){
    for(;x<=n;x+=lowbit(x)){
        tree[x]+=k;
    }
}

inline int query(int x){
    int sum=0;
    for(;x;x-=lowbit(x)) sum+=tree[x];
    return sum;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&nums[i]);
        nums[i].num=i;
    }
    sort(nums+1,nums+n+1,cmp);
    for(int i=1;i<=n;i++){
        rank_point[nums[i].num]=i;    //排序  进行离散化 从小的到大的 1 2 3 ... n
    }
    for(int i=1;i<=n;i++){
        update(rank_point[i],1);
        ans+=i-query(rank_point[i]);
    }
    printf("%lld",ans);
    return 0;
}
