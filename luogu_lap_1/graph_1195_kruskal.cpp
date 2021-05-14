//p1195 口袋的天空
//e=n-1  e=n-2 e=n-3  ... e=n-k k个连通分量
//kurskal

#include<bits/stdc++.h>
using namespace std;
const int maxn=1001,maxm=100001;
int n,m,k;
int father[maxn];
int ans=0,num_edges=0,cnt_edges=0;
struct Edge{
    int u;
    int v;
    int dis;
}edge[maxm];

inline int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}

inline void addedge(int a,int b,int c){
    num_edges++;
    edge[num_edges].u=a;
    edge[num_edges].v=b;
    edge[num_edges].dis=c;
}

bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
    }
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=num_edges;i++){
        int fa=findfather(edge[i].u),fb=findfather(edge[i].v);
        if(fa!=fb){
            father[fb]=fa;
            ans+=edge[i].dis;
            cnt_edges++;
            if(cnt_edges==n-k){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    if(cnt_edges!=n-k) cout<<"No Answer"<<endl;
    return 0;
}

