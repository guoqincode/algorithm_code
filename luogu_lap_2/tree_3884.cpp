#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
typedef struct{
    int lc;
    int rc;
    int layer;      //可以求每个节点在哪一层  -->求出某层有多少节点 
    int father;     //使用父节点来求从根节点到该节点的路径
}Node;
Node node[maxn];
int layer_nodes[maxn]={0};
int n,u,v,comfather,dis;
int maxlayer=-1,maxlayernodes=-1;
int root=1;
vector<int>father_a;
vector<int>father_b;
vector<int> find_father(int a){
    vector<int>res;
    while(node[a].father!=0){
        res.push_back(a);
        a=node[a].father;
    }
    res.push_back(root);
    return res;
}
int findcomfather(){
    int n=min(father_a.size(),father_b.size());
    for(int i=0;i<n-1;i++){
        if(father_a[i]==father_b[i]&&father_a[i+1]!=father_b[i+1]){
            return father_a[i];
        }
    }
    return 1;
}
int main(){
    cin>>n;
    node[1].layer=1;
    node[1].father=0;
    layer_nodes[1]=1;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(node[a].lc==0) node[a].lc=b;
        else node[a].rc=b;
        node[b].layer=node[a].layer+1;
        node[b].father=a;
        layer_nodes[node[b].layer]++;
        maxlayernodes=max(maxlayernodes,layer_nodes[node[b].layer]);
        maxlayer=max(maxlayer,node[b].layer);
    }
    // for(int i=1;i<=n;i++) cout<<node[i].layer<<" ";
    // cout<<endl;
    cin>>u>>v;
    father_a=find_father(u);
    father_b=find_father(v);
    reverse(father_a.begin(),father_a.end());
    reverse(father_b.begin(),father_b.end());
    comfather=findcomfather();
    dis=2*(node[u].layer-node[comfather].layer)+(node[v].layer-node[comfather].layer);
    cout<<maxlayer<<endl<<maxlayernodes<<endl<<dis;
    return 0;
}