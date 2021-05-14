//求最小生成树的kruskal写法
//并查集
#include<bits/stdc++.h>
using namespace std;
const int maxn=5001;
const int maxm=200001;
int father[maxn];
struct Edge{
    int u;
    int v;
    int dis;
}edge[maxm];

int ans=0,n,m,cnt;

bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}

int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}


void kruskal(){
    for(int i=1;i<=m;i++){
        int fa=findfather(edge[i].u),fb=findfather(edge[i].v);
        if(fa==fb) continue;
        ans+=edge[i].dis;
        father[fb]=fa;
        if(++cnt==n-1) break;      //边数为点数-1时候结束循环
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[i].u=a;
        edge[i].v=b;
        edge[i].dis=c;
    }
    sort(edge+1,edge+m+1,cmp);
    kruskal();
    if(cnt==n-1) cout<<ans;
    else cout<<"orz";
    return 0;
}