#include<bits/stdc++.h>
using namespace std;
int s,p;
const int maxn=501;
const int maxm=250010;
int a[maxn],b[maxn];
int num_edges=0;
int count_of_edges=0;
struct Edge{
    int from;
    int to;
    double dis;
}edge[maxm];

int father[maxn];
double ans;

inline double return_dis(int i,int j){
    return sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
}

bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}

int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}

inline void kruskal(){
    for(int i=1;i<=num_edges;i++){
        int fa=findfather(edge[i].from);
        int fb=findfather(edge[i].to);
        if(fa!=fb){
            ans=edge[i].dis;
            father[fb]=fa;
            count_of_edges++;
            if(count_of_edges>=p-s) return; //剩下的s个长边让卫星电话去连接
        }
    }
}

int main(){
    cin>>s>>p;
    for(int i=1;i<=p;i++){
        cin>>a[i]>>b[i];
        father[i]=i;
    }
    for(int i=1;i<=p-1;i++){
        for(int j=i+1;j<=p;j++){
            num_edges++;
            edge[num_edges].from=i;
            edge[num_edges].to=j;
            edge[num_edges].dis=return_dis(i,j);
        }
    }
    sort(edge+1,edge+num_edges+1,cmp);
    kruskal();
    printf("%.2lf",ans);
    // cout<<ans;
    return 0;
}