#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
const int maxm=2*50001;
const int INF=0x3f3f3f3f;
int n,m,b,f[maxn],fa[maxn];
int num_of_edges=0;
struct Edge{
    int dis;
    int to;
    int next;
}edge[maxm];
int head[maxn];
inline void addedge(int from,int to,int dis){
    num_of_edges++;
    edge[num_of_edges].next=head[from];
    edge[num_of_edges].to=to;
    edge[num_of_edges].dis=dis;
    head[from]=num_of_edges;
}

int isinq[maxn],d[maxn];
inline int can_this_through(int maxcost){
    //if can return 1 else return 0
    if(fa[1]>maxcost||fa[n]>maxcost) return 0;
    queue<int>q;
    fill(d+1,d+1+n,INF);
    d[1]=0;
    q.push(1);
    isinq[1]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        isinq[x]=0;
        for(int i=head[x];i;i=edge[i].next){
            int y=edge[i].to;
            if(d[y]>d[x]+edge[i].dis&&fa[y]<=maxcost){
                //只有在y点的花费<=maxcost 才能经过y点
                d[y]=d[x]+edge[i].dis;
                if(!isinq[y]){
                    q.push(y);
                    isinq[y]=1;
                }
            }
        }
    }
    if(d[n]<b) return 1;
    else return 0;
}


int main(){
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        fa[i]=f[i];
    }
    sort(f+1,f+n+1);    //->二分
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
        addedge(b,a,c);
    }
    if(!can_this_through(f[n])){
        cout<<"AFK";
        return 0;
    }
    int ans=f[n];
    int left=1,right=n;
    while (left<=right){
        int mid=(left+right)>>1;
        if(can_this_through(f[mid])){
            ans=f[mid];
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<ans;
}