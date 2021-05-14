//kruskal 部落划分
//和p1991无线通讯网类似
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
const int maxm=1e6+1;
int n,k,father[maxn],num_edges=0,cnt_fenliang=0;
double ans;
struct Node{
    int x;
    int y;
}node[maxn];
struct Edge{
    int from;
    int to;
    double dis;
}edge[maxm];

bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}

inline void init_father(){
    for(int i=1;i<=n;i++) father[i]=i;
}

inline double return_dis(int i,int j){
    return (double)(sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y)));
}

inline int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}

int main(){
    cin>>n>>k;
    init_father();
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        node[i].x=a;
        node[i].y=b;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            num_edges++;
            edge[num_edges].from=i;
            edge[num_edges].to=j;
            edge[num_edges].dis=return_dis(i,j);
        }
    }
    sort(edge+1,edge+num_edges+1,cmp);
    for(int i=1;i<=num_edges;i++){
        int fa=findfather(edge[i].from),fb=findfather(edge[i].to);
        if(fa!=fb){
            father[fb]=fa;
            cnt_fenliang++;
            if(cnt_fenliang==n-k+1){    //到n-k其实是挑选出最后一条边 到n-k+1才是最短的两个不连通区域的距离
                printf("%.2lf",edge[i].dis);
                return 0;
            }
        }
    }
    return 0;
}