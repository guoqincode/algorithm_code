//给定一个节点数为 n(n≤1e6)的树，节点编号为 1 , 2 , 3... n其中节点1为根节点
//每个节点上保存了一个数字，数字的值在int范围内(−2147483648∼2147483647)
//求对于树上的每一个节点，从根节点到该节点的路径上，有多少种不同的数字，按编号依次输出。
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n;
int a[maxn];
vector<int>vec_a;   //离散化用  这样res的大小就从int降低到了1e6

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x = x*10 + (ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int from,to,next;
}edge[maxn<<1];

int tot=0,head[maxn];
inline void addedge(int from,int to){
    tot++;
    edge[tot].from = from;
    edge[tot].to = to;
    edge[tot].next=head[from];
    head[from]=tot;
}

int cnt[maxn];
int ans=0;
int res[maxn];
inline void dfs(int x,int fa){
    if(cnt[a[x]] == 0) ans++;
    cnt[a[x]]++;
    res[x] = ans;
    for(int i = head[x]; i ; i=edge[i].next){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,x);
    }

    //回溯
    cnt[a[x]]--;
    if(cnt[a[x]]==0) ans--;
}

int main(){
    n=read();

    //这里有一个点就是
    for(int i=1;i<=n;i++){
        a[i]=read();
        vec_a.push_back(a[i]);
    }
    sort(vec_a.begin(),vec_a.end());
    for(int i=1;i<=n;i++) a[i]=lower_bound(vec_a.begin(),vec_a.end(),a[i])-vec_a.begin()+1;


    for(int i=1;i<=n-1;i++){
        int u,v;
        u=read(); v=read();
        addedge(u,v); addedge(v,u);
    }

    dfs(1,1);
    for(int i=1;i<=n;i++) cout<<res[i]<<endl;
    return 0;
}