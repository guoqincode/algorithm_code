//感觉是p1462 通往奥格瑞玛的道路 的简化版本
//用kruskal就可以做，当s与t连同时候 即father[s]==father[t] 输出当前边的权值
#include<bits/stdc++.h>
using namespace std;
const int maxn=10001,maxm=20001;
int n,m,s,t;
struct Edge{
    int u;
    int v;
    int dis;
}edge[maxm];
int father[maxn];

inline int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}
bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,dis;
        scanf("%d%d%d",&u,&v,&dis);
        edge[i].u=u;
        edge[i].v=v;
        edge[i].dis=dis;
    }
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fa=findfather(edge[i].u);
        int fb=findfather(edge[i].v);
        if(fa!=fb){
            father[fb]=fa;
        }
        if(findfather(s)==findfather(t)){   //注意时findfather()而不是father[]
            printf("%d",edge[i].dis);
            return 0;
        }
    }
    // cout<<father[s]<<" "<<father[t];
    return 0;
}