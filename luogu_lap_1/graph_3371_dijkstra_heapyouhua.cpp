//单源最短路的dijkstra+堆优化写法
//某些数据情况下sfpa会很慢，需要用dijkstra＋堆优化的写法
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+2;
const int maxm=5*1e5+2;
const int INF=(int)(pow(2,31)-1);
struct Edge{
    int next;   //起点相同的下一个边
    int to;     //该条边的终点
    int dis;
}edge[maxm];
int n,m,st,num_edge=0;     //num_edge记录边的个数
// int isinq[maxn];
int d[maxn],vis[maxn];
int head[maxn];     //

inline void addedge(int from,int to,int dis){
    //前向星式建图
    num_edge++;
    edge[num_edge].next=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
struct node{
    int pos;
    int dis;
    bool operator < (const node &x) const{
        return x.dis<dis;   //优先队列中出来的是最小的
    }
};
std::priority_queue<node>q;

inline void dijkstra_heap(int st){
    fill(d+1,d+n+1,INF);
    d[st]=0;
    // node s;
    // s.pos=st;
    // s.dis=0;
    q.push((node){st,0});
    while(!q.empty()){
        node temp=q.top();
        q.pop();
        int x=temp.pos;
        //int dd=temp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=edge[i].next){
            int y=edge[i].to;
            if(d[y]>d[x]+edge[i].dis){
                d[y]=d[x]+edge[i].dis;
                if(!vis[y]){
                    // q.push((node){d[y],y});
                    q.push((node){y,d[y]});
                }
            }
        }
    }
}
// void sfpa(int st){
//     queue<int>q;
//     fill(d+1,d+1+n,INF);
//     d[st]=0;
//     q.push(st);
//     isinq[st]=1;
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         isinq[u]=0; //不要忘记出队操作
//         for(int i=head[u];i;i=edge[i].next){
//             int v=edge[i].to;
//             if(d[v]>d[u]+edge[i].dis){
//                 d[v]=d[u]+edge[i].dis;
//                 if(isinq[v]==0){
//                     q.push(v);
//                     isinq[v]=1;
//                 }
//             }
//         }
//     }
// }
int main(){
    // ios::sync_with_stdio(false);
    // cin>>n>>m>>st;
    scanf( "%d%d%d", &n, &m, &st );
    for(register int i=1;i<=m;i++){
        register int u,v,w;
        scanf( "%d%d%d", &u, &v, &w );
        addedge(u,v,w);
    }
    // sfpa(st);
    dijkstra_heap(st);
    // for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    for(register int i=1;i<=n;i++) printf("%d ",d[i]);
    return 0;
}