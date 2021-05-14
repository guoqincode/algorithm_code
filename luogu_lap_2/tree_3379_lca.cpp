//最近公共祖先 LCA
//全部TLE 时间复杂度太高
#include<bits/stdc++.h>
using namespace std;
const int maxn=500001;
int father[maxn];      //存储父节点
int n,m,s;  //树的节点个数 询问次数 根节点序号
vector<int>path[maxn];

inline void find_path(int a){
    int q=a;
    // if(a==s){
    //     path[a].push_back(s);
    //     return;
    // }    father[s]=s 即可
    while(a!=s){
        path[q].push_back(a);
        a=father[a];
    }
    path[q].push_back(s);
    reverse(path[q].begin(),path[q].end());
}

inline int query_lca(int a,int b){
    if(path[a].empty()) find_path(a);
    if(path[b].empty()) find_path(b);
    int sizea=path[a].size(),sizeb=path[b].size();
    int i=0;
    while(i<min(sizea,sizeb)){
        if(path[a][i]==path[b][i]){
            i++;
            continue;
        }
        else return path[a][i-1];
    }
    if(i==min(sizea,sizeb)){
        if(sizea<sizeb) return path[a][sizea-1];
        else return path[b][sizeb-1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    father[s]=s;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        father[x]=y;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cout<<query_lca(a,b)<<endl;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<path[i].size();j++){
    //         cout<<path[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}