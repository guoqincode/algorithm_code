#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
int in_degree[maxn],f[maxn],dotime[maxn];    //入度  每个节点做完的时间  做完每单个节点所需时间
vector<int>next_nodes[maxn];
queue<int>q;
int n;
//找到递推式是关键
void toposort(){
    for(int i=1;i<=n;i++){  //  初始化
        if(in_degree[i]==0){
            q.push(i);
            f[i]=dotime[i];
        }
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<next_nodes[temp].size();i++){
            int u=next_nodes[temp][i];
            in_degree[u]--;
            if(in_degree[u]==0) q.push(u);
            f[u]=max(f[u],f[temp]+dotime[u]);     //***最重要的递推式
        }
        next_nodes[temp].clear();
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int tempd,temps;
        cin>>tempd;
        cin>>dotime[tempd];
        cin>>temps;
        while(temps){
            in_degree[tempd]++;
            next_nodes[temps].push_back(tempd);
            cin>>temps;
        }
    }
    toposort();
    int ans=-1;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    cout<<ans;
    return 0;
}