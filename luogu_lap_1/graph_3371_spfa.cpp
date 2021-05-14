//单源最短路的sfpa写法
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
int isinq[maxn],d[maxn];
int head[maxn];     //

void addedge(int from,int to,int dis){
    //前向星式建图
    num_edge++;
    edge[num_edge].next=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
void sfpa(int st){
    queue<int>q;
    fill(d+1,d+1+n,INF);
    d[st]=0;
    q.push(st);
    isinq[st]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        isinq[u]=0; //不要忘记出队操作
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(d[v]>d[u]+edge[i].dis){
                d[v]=d[u]+edge[i].dis;
                if(isinq[v]==0){
                    q.push(v);
                    isinq[v]=1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>st;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    sfpa(st);
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    return 0;
}