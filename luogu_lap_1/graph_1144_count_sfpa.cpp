#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int maxm=4*maxn;
const int mod=100003;
const int INF=(int)(pow(2,31)-1);
// struct Edge{
//     int next;
//     int to;
//     int dis;    //在这个题目中没用
// }edge[maxm];
int what_fuck_tototo[maxn],nxttt[maxn];
int nums_path[maxn],isinq[maxn],d[maxn],head[maxn],num_edges=0;
int n,m;

void addedge(int from,int too,int dis){
    // if(from==to) return;
    // num_edges++;
    // edge[num_edges].to=to;
    // // edge[num_edges].dis=dis;
    // edge[from].next=head[from];
    // head[from]=num_edges;
    what_fuck_tototo[++num_edges]=too;
    nxttt[num_edges]=head[from];
    head[from]=num_edges;
}

void sfpa(int st){
    queue<int>q;
    fill(d+1,d+n+1,INF);
    memset(isinq,0,sizeof(isinq));
    d[st]=0;
    nums_path[st]=1;
    q.push(st);
    isinq[st]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        isinq[x]=0;
        for(int i=head[x];i;i=nxttt[i]){
            int y=what_fuck_tototo[i];
            if(d[y]>d[x]+1){
                d[y]=d[x]+1;
                nums_path[y]=nums_path[x];
                if(!isinq[y]){
                    q.push(y);
                    isinq[y]=1;
                }
            }else if(d[y]==d[x]+1){
                nums_path[y]+=nums_path[x];
                nums_path[y]%=mod;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        //注意自环和重复边
        int u,v;
        cin>>u>>v;
        if(u==v) continue;
        addedge(u,v,0);
        addedge(v,u,0);
    }
    // cout<<edge[head[1]].to<<endl;
    sfpa(1);
    // for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++) cout<<nums_path[i]<<endl;
    return 0;
}