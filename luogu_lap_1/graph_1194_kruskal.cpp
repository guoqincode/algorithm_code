#include<bits/stdc++.h>
using namespace std;
const int maxn=5001,maxm=5001*5001+1;
int a,b;
struct Edge{
    int u;
    int v;
    int dis;
}edge[maxm];
int num_edges=0;
int father[maxn];
int ans=0;
inline int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}

//  Get_Father( x )         带路径压缩的并查集
//     {
//     	if x=Father[x]
//         	return x
//         else 
//         	return Father[x]=Get_Father(Father[x])
//     }
//     //路径压缩


bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}
int main(){
    scanf("%d%d",&a,&b);
    for(int i=1;i<=b;i++) father[i]=i;
    for(int i=1;i<=b;i++){
        for(int j=1;j<=b;j++){
            int x;
            scanf("%d",&x);
            if(x&&i<=j){
                num_edges++;
                edge[num_edges].u=i;
                edge[num_edges].v=j;
                edge[num_edges].dis=x;
            }
        }
    }
    sort(edge+1,edge+num_edges+1,cmp);
    for(int i=1;i<=num_edges;i++){
        int fa=findfather(edge[i].u);
        int fb=findfather(edge[i].v);
        if(fa!=fb){
            father[fb]=fa;
            if(edge[i].dis<a) ans+=edge[i].dis;
            else ans+=a;
        }
        // if(findfather(s)==findfather(t)){   //注意时findfather()而不是father[]
        //     printf("%d",edge[i].dis);
        //     return 0;
        // }
    }
    // cout<<father[s]<<" "<<father[t];
    cout<<ans+a<<endl;
    return 0;
}