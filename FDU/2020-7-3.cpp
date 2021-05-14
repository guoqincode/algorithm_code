//n个节点的树->图  0~n-1  初始时候全部是白色
//有两种操作 分别是对该节点进行染色 和 输出该节点到所有黑色节点距离之和
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
int father[maxn];
int tot=0,head[maxn],is_color[maxn];    //标记是否被染色了
int n,m;
struct Edge{
    int from;
    int to;
    int next;
    int dis;
}edge[maxn<<2]; //假设边的数量为4*maxn

inline void addedge(int from,int to,int dis){
    tot++;
    edge[tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    edge[tot].dis=dis;
    head[from]=tot;
}

// struct eedge{
//     //利用小顶堆来记录最小的边
//     int u,d;
//     bool operator < (const eedge& x) const{
//         return x.d<d;   //优先队列第一个是最小的那个
//     }
// };

// priority_queue<eedge>q;

int dis[maxn],vis[maxn];
inline int dijkstra(int st){
    fill(dis,dis+maxn,inf);
    memset(vis,0,sizeof(vis));  //每次dijkstra都要重新设置dis数组和访问数组！！！ 第一次就是因为没有设置访问数组导致的全0输出
    dis[st]=0;
    for(int kk=1;kk<=n;kk++){
        int u=-1,MIN=inf;
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1) break;
        vis[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(vis[v]==0&&dis[v]>dis[u]+edge[i].dis){
                dis[v]=dis[u]+edge[i].dis;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(is_color[i]==1&&dis[i]!=inf) ans+=dis[i];
    } 
    return ans;
}

int main(){
    //懒得用快读了 机试的时候再用把
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>father[i];
        father[i]++;
    }
    for(int i=2;i<=n;i++){
        int diss;
        cin>>diss;
        //节点 i 到他的父节点 father[i] 的距离
        addedge(i,father[i],diss);
        addedge(father[i],i,diss);
    }
    for(int i=1;i<=m;i++){
        int op,st; //OP==1染色   op==2查询
        cin>>op>>st;
        st++;
        if(op==1) is_color[st]=1;
        else cout<<dijkstra(st)<<endl;
    }
    return 0;
}
