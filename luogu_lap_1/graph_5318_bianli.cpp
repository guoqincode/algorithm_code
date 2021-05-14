#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m;
set<int>edge[maxn];
int vis[maxn]={0};

void dfs(int x){
    cout<<x<<" ";
    vis[x]=1;
    for(auto it=edge[x].begin();it!=edge[x].end();it++){
        if(vis[*it]==0){
            int temp=*it;
            dfs(temp);
        }
    }
}
void bfs(int x){
    queue<int>q;
    cout<<x<<" ";
    vis[x]=1;
    q.push(x);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto it=edge[temp].begin();it!=edge[temp].end();it++){
            if(vis[*it]==0){
                int tempn=*it;
                cout<<tempn<<" ";
                vis[tempn]=1;
                q.push(tempn);
            }
        }
    }
}


int main(){
    cin>>n>>m;
    int s,d;
    for(int i=1;i<=m;i++){
        cin>>s>>d;
        edge[s].insert(d);
    }
    dfs(1);
    cout<<endl;
    fill(vis+1,vis+n+1,0);
    bfs(1);
    return 0;
}