#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m;
vector<int>re_gra[maxn];
int vis[maxn]={0};  //既可以当访问数组 又可以记录该点可以到达的最远节点
void dfs(int x,int d){
    if(vis[x]) return;
    vis[x]=d;
    for(int i=0;i<re_gra[x].size();i++){
        dfs(re_gra[x][i],d);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        re_gra[v].push_back(u);     //反向建图
    }
    for(int i=n;i>=1;i--) dfs(i,i); //反向遍历
    for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
    return 0;
}