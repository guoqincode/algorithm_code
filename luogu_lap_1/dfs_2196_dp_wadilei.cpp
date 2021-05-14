#include<bits/stdc++.h>
using namespace std;
const int maxn=21;
vector<int>adj[maxn];   //邻接表的存储形式 adj[i]为空的话代表到最后一个了
int n,a[maxn],ans=-1;
int isnotfirst[maxn];  //用来判断“前面”是否有 1代表不是第一个 0代表是第一个
vector<int>path;
vector<int>anspath;
void dfs(int st){
    //从st开始走
    if(adj[st].empty()){
        //邻接表为空 走到了终点
        path.push_back(st);
        int temp=0;
        for(int i=0;i<path.size();i++){
            temp+=a[path[i]];
        }
        // ans=max(ans,temp);
        if(temp>ans){
            ans=temp;
            anspath=path;
        }
        path.pop_back();
        return;
    }
    path.push_back(st);
    for(int i=0;i<adj[st].size();i++){
        dfs(adj[st][i]);
    }
    path.pop_back();
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            int temp;
            cin>>temp;
            if(temp){
                adj[i].push_back(i+j);
                isnotfirst[i+j]=1;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        if(!isnotfirst[i]) dfs(i);  //起点一定是没有入度的点
    }
    for(int i=0;i<anspath.size();i++) cout<<anspath[i]<<" ";
    cout<<endl<<ans;
    return 0;
}