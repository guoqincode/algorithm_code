//给定一个节点数为 n(n≤1e6)的树，节点编号为 1 , 2 , 3... n其中节点1为根节点
//每个节点上保存了一个数字，数字的值在int范围内(−2147483648∼2147483647)
//求对于树上的每一个节点，从根节点到该节点的路径上，有多少种不同的数字，按编号依次输出。

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
struct Edge{
    int to,nxt;
}edge[maxn<<1];     //建立反向的边用于回溯

int n;
int head[maxn],tot=0;
inline void addedge(int from,int to){
    tot++;
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    head[from] = tot;
}

int a[maxn];
vector <int> vec_a;

int cnt[maxn];
int res;
int ans[maxn];
void dfs(int x,int fa){
    if(cnt[a[x]]==0) res++;
    cnt[a[x]]++;
    ans[x] = res;
    for(int i= head[x]; i ; i=edge[i].nxt){
        int v = edge[i].to;
        if(v==fa) continue;
        dfs(v,x);
    }
    cnt[a[x]]--;
    if(!cnt[a[x]]) res--;
}

int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        vec_a.push_back(a[i]);
    }
    sort(vec_a.begin(),vec_a.end());

    for(int i=1;i<=n;i++) a[i] = lower_bound(vec_a.begin(),vec_a.end(),a[i])-vec_a.begin()+1;

    int u,v;
    for(int i=1;i<=n;i++){
        cin>>u>>v;
        addedge(u,v);
    }

    dfs(1,1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}